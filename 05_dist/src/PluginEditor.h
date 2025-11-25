#pragma once
#include "PluginProcessor.h"
#include <JuceHeader.h>

class DistortionPluginEditor : public juce::AudioProcessorEditor {
public:
    explicit DistortionPluginEditor(DistortionPluginProcessor &);
    ~DistortionPluginEditor() override;

    void paint(juce::Graphics &) override;
    void resized() override;

private:
    DistortionPluginProcessor &audioProcessor;

    juce::Slider driveSlider;
    juce::Label driveLabel;
    juce::Slider mixSlider;
    juce::Label mixLabel;
    juce::Slider outputSlider;
    juce::Label outputLabel;

    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> driveAttachment;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> mixAttachment;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> outputAttachment;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(DistortionPluginEditor)
};
