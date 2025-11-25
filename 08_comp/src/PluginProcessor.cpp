#include "PluginProcessor.h"
#include "PluginEditor.h"

CompressorPluginProcessor::CompressorPluginProcessor()
    : AudioProcessor(
          BusesProperties()
              .withInput("Input", juce::AudioChannelSet::stereo())
              .withOutput("Output", juce::AudioChannelSet::stereo())),
      parameters(*this, nullptr, "Parameters",
                 {std::make_unique<juce::AudioParameterFloat>(
                      "threshold", "Threshold",
                      juce::NormalisableRange<float>(-60.0f, 0.0f, 0.01f),
                      -20.0f),
                  std::make_unique<juce::AudioParameterFloat>(
                      "ratio", "Ratio",
                      juce::NormalisableRange<float>(1.0f, 20.0f, 0.01f),
                      4.0f),
                  std::make_unique<juce::AudioParameterFloat>(
                      "attack", "Attack",
                      juce::NormalisableRange<float>(0.1f, 100.0f, 0.01f),
                      5.0f),
                  std::make_unique<juce::AudioParameterFloat>(
                      "release", "Release",
                      juce::NormalisableRange<float>(10.0f, 1000.0f, 0.01f),
                      100.0f)})
{
    thresholdParam = parameters.getRawParameterValue("threshold");
    ratioParam = parameters.getRawParameterValue("ratio");
    attackParam = parameters.getRawParameterValue("attack");
    releaseParam = parameters.getRawParameterValue("release");
}

CompressorPluginProcessor::~CompressorPluginProcessor() {}

void CompressorPluginProcessor::prepareToPlay(double sampleRate, int samplesPerBlock) {
    // TODO: Initialize compressor processing
}

void CompressorPluginProcessor::releaseResources() {}

void CompressorPluginProcessor::processBlock(juce::AudioBuffer<float> &buffer,
                                          juce::MidiBuffer &) {
    juce::ScopedNoDenormals noDenormals;

    // TODO: Implement compressor processing
    // For now, pass-through
}

juce::AudioProcessorEditor *CompressorPluginProcessor::createEditor() {
    return new CompressorPluginEditor(*this);
}

void CompressorPluginProcessor::getStateInformation(juce::MemoryBlock &destData) {
    auto state = parameters.copyState();
    std::unique_ptr<juce::XmlElement> xml(state.createXml());
    copyXmlToBinary(*xml, destData);
}

void CompressorPluginProcessor::setStateInformation(const void *data, int sizeInBytes) {
    std::unique_ptr<juce::XmlElement> xmlState(getXmlFromBinary(data, sizeInBytes));
    if (xmlState.get() != nullptr)
        if (xmlState->hasTagName(parameters.state.getType()))
            parameters.replaceState(juce::ValueTree::fromXml(*xmlState));
}

juce::AudioProcessor *JUCE_CALLTYPE createPluginFilter() {
    return new CompressorPluginProcessor();
}
