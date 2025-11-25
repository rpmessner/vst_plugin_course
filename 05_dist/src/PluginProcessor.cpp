#include "PluginProcessor.h"
#include "PluginEditor.h"

DistortionPluginProcessor::DistortionPluginProcessor()
    : AudioProcessor(
          BusesProperties()
              .withInput("Input", juce::AudioChannelSet::stereo())
              .withOutput("Output", juce::AudioChannelSet::stereo())),
      parameters(*this, nullptr, "Parameters",
                 {std::make_unique<juce::AudioParameterFloat>(
                      "drive", "Drive",
                      juce::NormalisableRange<float>(1.0f, 100.0f, 0.1f, 0.3f),
                      1.0f),
                  std::make_unique<juce::AudioParameterFloat>(
                      "mix", "Mix",
                      juce::NormalisableRange<float>(0.0f, 1.0f, 0.01f),
                      1.0f),
                  std::make_unique<juce::AudioParameterFloat>(
                      "output", "Output",
                      juce::NormalisableRange<float>(-24.0f, 24.0f, 0.1f),
                      0.0f)})
{
    driveParam = parameters.getRawParameterValue("drive");
    mixParam = parameters.getRawParameterValue("mix");
    outputParam = parameters.getRawParameterValue("output");
}

DistortionPluginProcessor::~DistortionPluginProcessor() {}

void DistortionPluginProcessor::prepareToPlay(double sampleRate, int samplesPerBlock) {
    // TODO: Initialize distortion processing
}

void DistortionPluginProcessor::releaseResources() {}

void DistortionPluginProcessor::processBlock(juce::AudioBuffer<float> &buffer,
                                             juce::MidiBuffer &) {
    juce::ScopedNoDenormals noDenormals;

    // TODO: Implement distortion processing (waveshaping, saturation, etc.)
    // For now, pass-through
}

juce::AudioProcessorEditor *DistortionPluginProcessor::createEditor() {
    return new DistortionPluginEditor(*this);
}

void DistortionPluginProcessor::getStateInformation(juce::MemoryBlock &destData) {
    auto state = parameters.copyState();
    std::unique_ptr<juce::XmlElement> xml(state.createXml());
    copyXmlToBinary(*xml, destData);
}

void DistortionPluginProcessor::setStateInformation(const void *data, int sizeInBytes) {
    std::unique_ptr<juce::XmlElement> xmlState(getXmlFromBinary(data, sizeInBytes));
    if (xmlState.get() != nullptr)
        if (xmlState->hasTagName(parameters.state.getType()))
            parameters.replaceState(juce::ValueTree::fromXml(*xmlState));
}

juce::AudioProcessor *JUCE_CALLTYPE createPluginFilter() {
    return new DistortionPluginProcessor();
}
