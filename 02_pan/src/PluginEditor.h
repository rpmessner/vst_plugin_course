#pragma once
#include "PluginProcessor.h"
#include <JuceHeader.h>

class PanPluginEditor : public juce::AudioProcessorEditor {
public:
    explicit PanPluginEditor(PanPluginProcessor &);
    ~PanPluginEditor() override;

    void paint(juce::Graphics &) override;
    void resized() override;

private:
    PanPluginProcessor &audioProcessor;

    juce::Slider panSlider;
    juce::Label panLabel;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> panAttachment;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(PanPluginEditor)
};
