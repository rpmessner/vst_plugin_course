#include "PluginProcessor.h"
#include "PluginEditor.h"

FilterPluginProcessor::FilterPluginProcessor()
    : AudioProcessor(
          BusesProperties()
              .withInput("Input", juce::AudioChannelSet::stereo())
              .withOutput("Output", juce::AudioChannelSet::stereo())),
      parameters(*this, nullptr, "Parameters",
                 {std::make_unique<juce::AudioParameterChoice>(
                      "filterType", "Filter Type",
                      juce::StringArray{"Low Pass", "High Pass", "Band Pass"},
                      0),
                  std::make_unique<juce::AudioParameterFloat>(
                      "cutoff", "Cutoff",
                      juce::NormalisableRange<float>(20.0f, 20000.0f, 1.0f, 0.3f),
                      1000.0f),
                  std::make_unique<juce::AudioParameterFloat>(
                      "resonance", "Resonance",
                      juce::NormalisableRange<float>(0.1f, 10.0f, 0.1f),
                      0.707f)})
{
    filterTypeParam = parameters.getRawParameterValue("filterType");
    cutoffParam = parameters.getRawParameterValue("cutoff");
    resonanceParam = parameters.getRawParameterValue("resonance");
}

FilterPluginProcessor::~FilterPluginProcessor() {}

void FilterPluginProcessor::prepareToPlay(double sampleRate, int samplesPerBlock) {
    // TODO: Initialize filter processing
}

void FilterPluginProcessor::releaseResources() {}

void FilterPluginProcessor::processBlock(juce::AudioBuffer<float> &buffer,
                                         juce::MidiBuffer &) {
    juce::ScopedNoDenormals noDenormals;

    // TODO: Implement filter processing
    // For now, pass-through
}

juce::AudioProcessorEditor *FilterPluginProcessor::createEditor() {
    return new FilterPluginEditor(*this);
}

void FilterPluginProcessor::getStateInformation(juce::MemoryBlock &destData) {
    auto state = parameters.copyState();
    std::unique_ptr<juce::XmlElement> xml(state.createXml());
    copyXmlToBinary(*xml, destData);
}

void FilterPluginProcessor::setStateInformation(const void *data, int sizeInBytes) {
    std::unique_ptr<juce::XmlElement> xmlState(getXmlFromBinary(data, sizeInBytes));
    if (xmlState.get() != nullptr)
        if (xmlState->hasTagName(parameters.state.getType()))
            parameters.replaceState(juce::ValueTree::fromXml(*xmlState));
}

juce::AudioProcessor *JUCE_CALLTYPE createPluginFilter() {
    return new FilterPluginProcessor();
}
