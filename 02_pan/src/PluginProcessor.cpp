#include "PluginProcessor.h"
#include "PluginEditor.h"

PanPluginProcessor::PanPluginProcessor()
    : AudioProcessor(
          BusesProperties()
              .withInput("Input", juce::AudioChannelSet::stereo())
              .withOutput("Output", juce::AudioChannelSet::stereo())),
      parameters(*this, nullptr, "Parameters",
                 {std::make_unique<juce::AudioParameterFloat>(
                     "pan", "Pan",
                     juce::NormalisableRange<float>(-1.0f, 1.0f, 0.01f),
                     0.0f)})
{
    panParam = parameters.getRawParameterValue("pan");
}

PanPluginProcessor::~PanPluginProcessor() {}

void PanPluginProcessor::prepareToPlay(double sampleRate, int samplesPerBlock) {
    smoothedPan.reset(sampleRate, 0.05); // 50ms smoothing
    smoothedPan.setCurrentAndTargetValue(panParam->load());
}

void PanPluginProcessor::releaseResources() {}

void PanPluginProcessor::processBlock(juce::AudioBuffer<float> &buffer,
                                      juce::MidiBuffer &) {
    juce::ScopedNoDenormals noDenormals;

    if (buffer.getNumChannels() < 2)
        return;

    // Update smoothed pan from parameter
    smoothedPan.setTargetValue(panParam->load());

    auto *leftChannel = buffer.getWritePointer(0);
    auto *rightChannel = buffer.getWritePointer(1);

    // Apply linear panning law
    for (int sample = 0; sample < buffer.getNumSamples(); ++sample) {
        float pan = smoothedPan.getNextValue();

        // Linear pan: -1 = full left, 0 = center, +1 = full right
        float leftGain = (1.0f - pan) * 0.5f;
        float rightGain = (1.0f + pan) * 0.5f;

        leftChannel[sample] *= leftGain;
        rightChannel[sample] *= rightGain;
    }
}

juce::AudioProcessorEditor *PanPluginProcessor::createEditor() {
    return new PanPluginEditor(*this);
}

void PanPluginProcessor::getStateInformation(juce::MemoryBlock &destData) {
    auto state = parameters.copyState();
    std::unique_ptr<juce::XmlElement> xml(state.createXml());
    copyXmlToBinary(*xml, destData);
}

void PanPluginProcessor::setStateInformation(const void *data, int sizeInBytes) {
    std::unique_ptr<juce::XmlElement> xmlState(getXmlFromBinary(data, sizeInBytes));
    if (xmlState.get() != nullptr)
        if (xmlState->hasTagName(parameters.state.getType()))
            parameters.replaceState(juce::ValueTree::fromXml(*xmlState));
}

juce::AudioProcessor *JUCE_CALLTYPE createPluginFilter() {
    return new PanPluginProcessor();
}
