#include "PluginProcessor.h"
#include "PluginEditor.h"

ReverbPluginProcessor::ReverbPluginProcessor()
    : AudioProcessor(
          BusesProperties()
              .withInput("Input", juce::AudioChannelSet::stereo())
              .withOutput("Output", juce::AudioChannelSet::stereo())),
      parameters(*this, nullptr, "Parameters",
                 {std::make_unique<juce::AudioParameterFloat>(
                      "roomSize", "Room Size",
                      juce::NormalisableRange<float>(0.0f, 1.0f, 0.01f),
                      0.5f),
                  std::make_unique<juce::AudioParameterFloat>(
                      "damping", "Damping",
                      juce::NormalisableRange<float>(0.0f, 1.0f, 0.01f),
                      0.5f),
                  std::make_unique<juce::AudioParameterFloat>(
                      "mix", "Mix",
                      juce::NormalisableRange<float>(0.0f, 1.0f, 0.01f),
                      0.3f)})
{
    roomSizeParam = parameters.getRawParameterValue("roomSize");
    dampingParam = parameters.getRawParameterValue("damping");
    mixParam = parameters.getRawParameterValue("mix");
}

ReverbPluginProcessor::~ReverbPluginProcessor() {}

void ReverbPluginProcessor::prepareToPlay(double sampleRate, int samplesPerBlock) {
    // TODO: Initialize reverb processing
}

void ReverbPluginProcessor::releaseResources() {}

void ReverbPluginProcessor::processBlock(juce::AudioBuffer<float> &buffer,
                                          juce::MidiBuffer &) {
    juce::ScopedNoDenormals noDenormals;

    // TODO: Implement reverb processing
    // For now, pass-through
}

juce::AudioProcessorEditor *ReverbPluginProcessor::createEditor() {
    return new ReverbPluginEditor(*this);
}

void ReverbPluginProcessor::getStateInformation(juce::MemoryBlock &destData) {
    auto state = parameters.copyState();
    std::unique_ptr<juce::XmlElement> xml(state.createXml());
    copyXmlToBinary(*xml, destData);
}

void ReverbPluginProcessor::setStateInformation(const void *data, int sizeInBytes) {
    std::unique_ptr<juce::XmlElement> xmlState(getXmlFromBinary(data, sizeInBytes));
    if (xmlState.get() != nullptr)
        if (xmlState->hasTagName(parameters.state.getType()))
            parameters.replaceState(juce::ValueTree::fromXml(*xmlState));
}

juce::AudioProcessor *JUCE_CALLTYPE createPluginFilter() {
    return new ReverbPluginProcessor();
}
