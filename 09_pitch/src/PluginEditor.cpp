#include "PluginEditor.h"

PitchPluginEditor::PitchPluginEditor(PitchPluginProcessor &p)
    : AudioProcessorEditor(&p), audioProcessor(p) {
    setSize(400, 400);

    // Pitch Shift slider
    pitchShiftSlider.setSliderStyle(juce::Slider::RotaryHorizontalVerticalDrag);
    pitchShiftSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 80, 20);
    pitchShiftSlider.setTextValueSuffix(" st");
    addAndMakeVisible(pitchShiftSlider);
    pitchShiftLabel.setText("Pitch Shift", juce::dontSendNotification);
    pitchShiftLabel.setJustificationType(juce::Justification::centred);
    addAndMakeVisible(pitchShiftLabel);
    pitchShiftAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(
        audioProcessor.getValueTreeState(), "pitchShift", pitchShiftSlider);

    // Mix slider
    mixSlider.setSliderStyle(juce::Slider::RotaryHorizontalVerticalDrag);
    mixSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 80, 20);
    mixSlider.setTextValueSuffix("");
    addAndMakeVisible(mixSlider);
    mixLabel.setText("Mix", juce::dontSendNotification);
    mixLabel.setJustificationType(juce::Justification::centred);
    addAndMakeVisible(mixLabel);
    mixAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(
        audioProcessor.getValueTreeState(), "mix", mixSlider);
}

PitchPluginEditor::~PitchPluginEditor() {}

void PitchPluginEditor::paint(juce::Graphics &g) {
    g.fillAll(juce::Colours::darkgrey);
}

void PitchPluginEditor::resized() {
    auto area = getLocalBounds().reduced(20);

    pitchShiftLabel.setBounds(area.removeFromTop(30));
    pitchShiftSlider.setBounds(area.removeFromTop(120));

    mixLabel.setBounds(area.removeFromTop(30));
    mixSlider.setBounds(area.removeFromTop(120));
}
