#pragma once
#include "PluginProcessor.h"
#include <JuceHeader.h>

class CompressorPluginEditor : public juce::AudioProcessorEditor {
public:
    explicit CompressorPluginEditor(CompressorPluginProcessor &);
    ~CompressorPluginEditor() override;

    void paint(juce::Graphics &) override;
    void resized() override;

private:
    CompressorPluginProcessor &audioProcessor;

    juce::Slider thresholdSlider;
    juce::Label thresholdLabel;
    juce::Slider ratioSlider;
    juce::Label ratioLabel;
    juce::Slider attackSlider;
    juce::Label attackLabel;
    juce::Slider releaseSlider;
    juce::Label releaseLabel;

    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> thresholdAttachment;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> ratioAttachment;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> attackAttachment;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> releaseAttachment;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(CompressorPluginEditor)
};
