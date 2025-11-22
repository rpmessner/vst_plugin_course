#include "PluginProcessor.h"
#include "PluginEditor.h"

GainPluginProcessor::GainPluginProcessor()
    : AudioProcessor(
          BusesProperties()
              .withInput("Input", juce::AudioChannelSet::stereo())
              .withOutput("Output", juce::AudioChannelSet::stereo())),
      parameters(*this, nullptr, "Parameters",
                 {std::make_unique<juce::AudioParameterFloat>(
                     "gain", "Gain",
                     juce::NormalisableRange<float>(-60.0f, 12.0f, 0.1f),
                     0.0f)})
{
    gainParam = parameters.getRawParameterValue("gain");
}

GainPluginProcessor::~GainPluginProcessor() {}

void GainPluginProcessor::prepareToPlay(double sampleRate, int samplesPerBlock) {
    smoothedGain.reset(sampleRate, 0.05); // 50ms smoothing
    smoothedGain.setCurrentAndTargetValue(juce::Decibels::decibelsToGain(gainParam->load()));
}

void GainPluginProcessor::releaseResources() {}

void GainPluginProcessor::processBlock(juce::AudioBuffer<float> &buffer,
                                       juce::MidiBuffer &) {
    juce::ScopedNoDenormals noDenormals;

    // Update smoothed gain from parameter
    smoothedGain.setTargetValue(juce::Decibels::decibelsToGain(gainParam->load()));

    // Apply gain to each sample
    for (int channel = 0; channel < buffer.getNumChannels(); ++channel) {
        auto *channelData = buffer.getWritePointer(channel);

        for (int sample = 0; sample < buffer.getNumSamples(); ++sample) {
            channelData[sample] *= smoothedGain.getNextValue();
        }
    }
}

juce::AudioProcessorEditor *GainPluginProcessor::createEditor() {
    return new GainPluginEditor(*this);
}

void GainPluginProcessor::getStateInformation(juce::MemoryBlock &destData) {
    auto state = parameters.copyState();
    std::unique_ptr<juce::XmlElement> xml(state.createXml());
    copyXmlToBinary(*xml, destData);
}

void GainPluginProcessor::setStateInformation(const void *data, int sizeInBytes) {
    std::unique_ptr<juce::XmlElement> xmlState(getXmlFromBinary(data, sizeInBytes));
    if (xmlState.get() != nullptr)
        if (xmlState->hasTagName(parameters.state.getType()))
            parameters.replaceState(juce::ValueTree::fromXml(*xmlState));
}

juce::AudioProcessor *JUCE_CALLTYPE createPluginFilter() {
    return new GainPluginProcessor();
}
