#include "PluginProcessor.h"
#include "PluginEditor.h"

SpectralPluginProcessor::SpectralPluginProcessor()
    : AudioProcessor(
          BusesProperties()
              .withInput("Input", juce::AudioChannelSet::stereo())
              .withOutput("Output", juce::AudioChannelSet::stereo())),
      parameters(*this, nullptr, "Parameters",
                 {std::make_unique<juce::AudioParameterFloat>(
                      "fftSize", "FFT Size",
                      juce::NormalisableRange<float>(6.0f, 13.0f, 0.01f),
                      11.0f),
                  std::make_unique<juce::AudioParameterFloat>(
                      "threshold", "Threshold",
                      juce::NormalisableRange<float>(-96.0f, 0.0f, 0.01f),
                      -60.0f)})
{
    fftSizeParam = parameters.getRawParameterValue("fftSize");
    thresholdParam = parameters.getRawParameterValue("threshold");
}

SpectralPluginProcessor::~SpectralPluginProcessor() {}

void SpectralPluginProcessor::prepareToPlay(double sampleRate, int samplesPerBlock) {
    // TODO: Initialize spectral processing
}

void SpectralPluginProcessor::releaseResources() {}

void SpectralPluginProcessor::processBlock(juce::AudioBuffer<float> &buffer,
                                          juce::MidiBuffer &) {
    juce::ScopedNoDenormals noDenormals;

    // TODO: Implement spectral processing
    // For now, pass-through
}

juce::AudioProcessorEditor *SpectralPluginProcessor::createEditor() {
    return new SpectralPluginEditor(*this);
}

void SpectralPluginProcessor::getStateInformation(juce::MemoryBlock &destData) {
    auto state = parameters.copyState();
    std::unique_ptr<juce::XmlElement> xml(state.createXml());
    copyXmlToBinary(*xml, destData);
}

void SpectralPluginProcessor::setStateInformation(const void *data, int sizeInBytes) {
    std::unique_ptr<juce::XmlElement> xmlState(getXmlFromBinary(data, sizeInBytes));
    if (xmlState.get() != nullptr)
        if (xmlState->hasTagName(parameters.state.getType()))
            parameters.replaceState(juce::ValueTree::fromXml(*xmlState));
}

juce::AudioProcessor *JUCE_CALLTYPE createPluginFilter() {
    return new SpectralPluginProcessor();
}
