#pragma once
#include "PluginProcessor.h"
#include <JuceHeader.h>

class DelayPluginEditor : public juce::AudioProcessorEditor {
public:
    explicit DelayPluginEditor(DelayPluginProcessor &);
    ~DelayPluginEditor() override;

    void paint(juce::Graphics &) override;
    void resized() override;

private:
    DelayPluginProcessor &audioProcessor;

    juce::Slider delayTimeSlider;
    juce::Label delayTimeLabel;
    juce::Slider feedbackSlider;
    juce::Label feedbackLabel;
    juce::Slider mixSlider;
    juce::Label mixLabel;

    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> delayTimeAttachment;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> feedbackAttachment;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> mixAttachment;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(DelayPluginEditor)
};
