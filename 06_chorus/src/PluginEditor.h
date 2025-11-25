#pragma once
#include "PluginProcessor.h"
#include <JuceHeader.h>

class ChorusPluginEditor : public juce::AudioProcessorEditor {
public:
    explicit ChorusPluginEditor(ChorusPluginProcessor &);
    ~ChorusPluginEditor() override;

    void paint(juce::Graphics &) override;
    void resized() override;

private:
    ChorusPluginProcessor &audioProcessor;

    juce::Slider rateSlider;
    juce::Label rateLabel;
    juce::Slider depthSlider;
    juce::Label depthLabel;
    juce::Slider mixSlider;
    juce::Label mixLabel;

    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> rateAttachment;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> depthAttachment;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> mixAttachment;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(ChorusPluginEditor)
};
