#include "PluginProcessor.h"
#include "PluginEditor.h"

DelayPluginProcessor::DelayPluginProcessor()
    : AudioProcessor(
          BusesProperties()
              .withInput("Input", juce::AudioChannelSet::stereo())
              .withOutput("Output", juce::AudioChannelSet::stereo())),
      parameters(*this, nullptr, "Parameters",
                 {std::make_unique<juce::AudioParameterFloat>(
                      "delayTime", "Delay Time",
                      juce::NormalisableRange<float>(0.0f, 2000.0f, 1.0f),
                      500.0f),
                  std::make_unique<juce::AudioParameterFloat>(
                      "feedback", "Feedback",
                      juce::NormalisableRange<float>(0.0f, 0.95f, 0.01f),
                      0.3f),
                  std::make_unique<juce::AudioParameterFloat>(
                      "mix", "Mix",
                      juce::NormalisableRange<float>(0.0f, 1.0f, 0.01f),
                      0.5f)})
{
    delayTimeParam = parameters.getRawParameterValue("delayTime");
    feedbackParam = parameters.getRawParameterValue("feedback");
    mixParam = parameters.getRawParameterValue("mix");
}

DelayPluginProcessor::~DelayPluginProcessor() {}

void DelayPluginProcessor::prepareToPlay(double sampleRate, int samplesPerBlock) {
    // TODO: Initialize delay buffer and processing
}

void DelayPluginProcessor::releaseResources() {}

void DelayPluginProcessor::processBlock(juce::AudioBuffer<float> &buffer,
                                        juce::MidiBuffer &) {
    juce::ScopedNoDenormals noDenormals;

    // TODO: Implement delay processing
    // For now, pass-through
}

juce::AudioProcessorEditor *DelayPluginProcessor::createEditor() {
    return new DelayPluginEditor(*this);
}

void DelayPluginProcessor::getStateInformation(juce::MemoryBlock &destData) {
    auto state = parameters.copyState();
    std::unique_ptr<juce::XmlElement> xml(state.createXml());
    copyXmlToBinary(*xml, destData);
}

void DelayPluginProcessor::setStateInformation(const void *data, int sizeInBytes) {
    std::unique_ptr<juce::XmlElement> xmlState(getXmlFromBinary(data, sizeInBytes));
    if (xmlState.get() != nullptr)
        if (xmlState->hasTagName(parameters.state.getType()))
            parameters.replaceState(juce::ValueTree::fromXml(*xmlState));
}

juce::AudioProcessor *JUCE_CALLTYPE createPluginFilter() {
    return new DelayPluginProcessor();
}
