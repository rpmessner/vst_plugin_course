#include "PluginProcessor.h"
#include "PluginEditor.h"

PitchPluginProcessor::PitchPluginProcessor()
    : AudioProcessor(
          BusesProperties()
              .withInput("Input", juce::AudioChannelSet::stereo())
              .withOutput("Output", juce::AudioChannelSet::stereo())),
      parameters(*this, nullptr, "Parameters",
                 {std::make_unique<juce::AudioParameterFloat>(
                      "pitchShift", "Pitch Shift",
                      juce::NormalisableRange<float>(-12.0f, 12.0f, 0.01f),
                      0.0f),
                  std::make_unique<juce::AudioParameterFloat>(
                      "mix", "Mix",
                      juce::NormalisableRange<float>(0.0f, 1.0f, 0.01f),
                      1.0f)})
{
    pitchShiftParam = parameters.getRawParameterValue("pitchShift");
    mixParam = parameters.getRawParameterValue("mix");
}

PitchPluginProcessor::~PitchPluginProcessor() {}

void PitchPluginProcessor::prepareToPlay(double sampleRate, int samplesPerBlock) {
    // TODO: Initialize pitch processing
}

void PitchPluginProcessor::releaseResources() {}

void PitchPluginProcessor::processBlock(juce::AudioBuffer<float> &buffer,
                                          juce::MidiBuffer &) {
    juce::ScopedNoDenormals noDenormals;

    // TODO: Implement pitch processing
    // For now, pass-through
}

juce::AudioProcessorEditor *PitchPluginProcessor::createEditor() {
    return new PitchPluginEditor(*this);
}

void PitchPluginProcessor::getStateInformation(juce::MemoryBlock &destData) {
    auto state = parameters.copyState();
    std::unique_ptr<juce::XmlElement> xml(state.createXml());
    copyXmlToBinary(*xml, destData);
}

void PitchPluginProcessor::setStateInformation(const void *data, int sizeInBytes) {
    std::unique_ptr<juce::XmlElement> xmlState(getXmlFromBinary(data, sizeInBytes));
    if (xmlState.get() != nullptr)
        if (xmlState->hasTagName(parameters.state.getType()))
            parameters.replaceState(juce::ValueTree::fromXml(*xmlState));
}

juce::AudioProcessor *JUCE_CALLTYPE createPluginFilter() {
    return new PitchPluginProcessor();
}
