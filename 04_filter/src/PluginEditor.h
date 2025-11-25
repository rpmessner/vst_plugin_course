#pragma once
#include "PluginProcessor.h"
#include <JuceHeader.h>

class FilterPluginEditor : public juce::AudioProcessorEditor {
public:
    explicit FilterPluginEditor(FilterPluginProcessor &);
    ~FilterPluginEditor() override;

    void paint(juce::Graphics &) override;
    void resized() override;

private:
    FilterPluginProcessor &audioProcessor;

    juce::ComboBox filterTypeCombo;
    juce::Label filterTypeLabel;
    juce::Slider cutoffSlider;
    juce::Label cutoffLabel;
    juce::Slider resonanceSlider;
    juce::Label resonanceLabel;

    std::unique_ptr<juce::AudioProcessorValueTreeState::ComboBoxAttachment> filterTypeAttachment;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> cutoffAttachment;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> resonanceAttachment;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(FilterPluginEditor)
};
