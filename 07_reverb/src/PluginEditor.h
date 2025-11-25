#pragma once
#include "PluginProcessor.h"
#include <JuceHeader.h>

class ReverbPluginEditor : public juce::AudioProcessorEditor {
public:
    explicit ReverbPluginEditor(ReverbPluginProcessor &);
    ~ReverbPluginEditor() override;

    void paint(juce::Graphics &) override;
    void resized() override;

private:
    ReverbPluginProcessor &audioProcessor;

    juce::Slider roomSizeSlider;
    juce::Label roomSizeLabel;
    juce::Slider dampingSlider;
    juce::Label dampingLabel;
    juce::Slider mixSlider;
    juce::Label mixLabel;

    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> roomSizeAttachment;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> dampingAttachment;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> mixAttachment;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ReverbPluginEditor)
};
