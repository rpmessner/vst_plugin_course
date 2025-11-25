#pragma once
#include "PluginProcessor.h"
#include <JuceHeader.h>

class PitchPluginEditor : public juce::AudioProcessorEditor {
public:
    explicit PitchPluginEditor(PitchPluginProcessor &);
    ~PitchPluginEditor() override;

    void paint(juce::Graphics &) override;
    void resized() override;

private:
    PitchPluginProcessor &audioProcessor;

    juce::Slider pitchShiftSlider;
    juce::Label pitchShiftLabel;
    juce::Slider mixSlider;
    juce::Label mixLabel;

    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> pitchShiftAttachment;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> mixAttachment;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(PitchPluginEditor)
};
