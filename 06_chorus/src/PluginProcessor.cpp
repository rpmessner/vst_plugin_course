#include "PluginProcessor.h"
#include "PluginEditor.h"

ChorusPluginProcessor::ChorusPluginProcessor()
    : AudioProcessor(
          BusesProperties()
              .withInput("Input", juce::AudioChannelSet::stereo())
              .withOutput("Output", juce::AudioChannelSet::stereo())),
      parameters(*this, nullptr, "Parameters",
                 {std::make_unique<juce::AudioParameterFloat>(
                      "rate", "Rate",
                      juce::NormalisableRange<float>(0.1f, 10.0f, 0.01f),
                      1.0f),
                  std::make_unique<juce::AudioParameterFloat>(
                      "depth", "Depth",
                      juce::NormalisableRange<float>(0.0f, 1.0f, 0.01f),
                      0.5f),
                  std::make_unique<juce::AudioParameterFloat>(
                      "mix", "Mix",
                      juce::NormalisableRange<float>(0.0f, 1.0f, 0.01f),
                      0.5f)})
{
    rateParam = parameters.getRawParameterValue("rate");
    depthParam = parameters.getRawParameterValue("depth");
    mixParam = parameters.getRawParameterValue("mix");
}

ChorusPluginProcessor::~ChorusPluginProcessor() {}

void ChorusPluginProcessor::prepareToPlay(double sampleRate, int samplesPerBlock) {
    // TODO: Initialize chorus processing
}

void ChorusPluginProcessor::releaseResources() {}

void ChorusPluginProcessor::processBlock(juce::AudioBuffer<float> &buffer,
                                          juce::MidiBuffer &) {
    juce::ScopedNoDenormals noDenormals;

    // TODO: Implement chorus processing
    // For now, pass-through
}

juce::AudioProcessorEditor *ChorusPluginProcessor::createEditor() {
    return new ChorusPluginEditor(*this);
}

void ChorusPluginProcessor::getStateInformation(juce::MemoryBlock &destData) {
    auto state = parameters.copyState();
    std::unique_ptr<juce::XmlElement> xml(state.createXml());
    copyXmlToBinary(*xml, destData);
}

void ChorusPluginProcessor::setStateInformation(const void *data, int sizeInBytes) {
    std::unique_ptr<juce::XmlElement> xmlState(getXmlFromBinary(data, sizeInBytes));
    if (xmlState.get() != nullptr)
        if (xmlState->hasTagName(parameters.state.getType()))
            parameters.replaceState(juce::ValueTree::fromXml(*xmlState));
}

juce::AudioProcessor *JUCE_CALLTYPE createPluginFilter() {
    return new ChorusPluginProcessor();
}
