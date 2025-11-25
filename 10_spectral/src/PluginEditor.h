#pragma once
#include "PluginProcessor.h"
#include <JuceHeader.h>

class SpectralPluginEditor : public juce::AudioProcessorEditor {
public:
    explicit SpectralPluginEditor(SpectralPluginProcessor &);
    ~SpectralPluginEditor() override;

    void paint(juce::Graphics &) override;
    void resized() override;

private:
    SpectralPluginProcessor &audioProcessor;

    juce::Slider fftSizeSlider;
    juce::Label fftSizeLabel;
    juce::Slider thresholdSlider;
    juce::Label thresholdLabel;

    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> fftSizeAttachment;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> thresholdAttachment;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(SpectralPluginEditor)
};
