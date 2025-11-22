#pragma once
#include "PluginProcessor.h"
#include <JuceHeader.h>

class GainPluginEditor : public juce::AudioProcessorEditor {
public:
    explicit GainPluginEditor(GainPluginProcessor &);
    ~GainPluginEditor() override;

    void paint(juce::Graphics &) override;
    void resized() override;

private:
    GainPluginProcessor &audioProcessor;

    juce::Slider gainSlider;
    juce::Label gainLabel;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> gainAttachment;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(GainPluginEditor)
};
