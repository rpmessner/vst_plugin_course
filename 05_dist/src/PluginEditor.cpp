#include "PluginEditor.h"

DistortionPluginEditor::DistortionPluginEditor(DistortionPluginProcessor &p)
    : AudioProcessorEditor(&p), audioProcessor(p) {
    setSize(400, 400);

    // Drive slider
    driveSlider.setSliderStyle(juce::Slider::RotaryHorizontalVerticalDrag);
    driveSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 80, 20);
    addAndMakeVisible(driveSlider);
    driveLabel.setText("Drive", juce::dontSendNotification);
    driveLabel.setJustificationType(juce::Justification::centred);
    addAndMakeVisible(driveLabel);
    driveAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(
        audioProcessor.getValueTreeState(), "drive", driveSlider);

    // Mix slider
    mixSlider.setSliderStyle(juce::Slider::RotaryHorizontalVerticalDrag);
    mixSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 80, 20);
    addAndMakeVisible(mixSlider);
    mixLabel.setText("Mix", juce::dontSendNotification);
    mixLabel.setJustificationType(juce::Justification::centred);
    addAndMakeVisible(mixLabel);
    mixAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(
        audioProcessor.getValueTreeState(), "mix", mixSlider);

    // Output slider
    outputSlider.setSliderStyle(juce::Slider::RotaryHorizontalVerticalDrag);
    outputSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 80, 20);
    outputSlider.setTextValueSuffix(" dB");
    addAndMakeVisible(outputSlider);
    outputLabel.setText("Output", juce::dontSendNotification);
    outputLabel.setJustificationType(juce::Justification::centred);
    addAndMakeVisible(outputLabel);
    outputAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(
        audioProcessor.getValueTreeState(), "output", outputSlider);
}

DistortionPluginEditor::~DistortionPluginEditor() {}

void DistortionPluginEditor::paint(juce::Graphics &g) {
    g.fillAll(juce::Colours::darkgrey);
}

void DistortionPluginEditor::resized() {
    auto area = getLocalBounds().reduced(20);

    driveLabel.setBounds(area.removeFromTop(30));
    driveSlider.setBounds(area.removeFromTop(120));

    auto row = area.removeFromTop(150);
    auto mixArea = row.removeFromLeft(getWidth() / 2);

    mixLabel.setBounds(mixArea.removeFromTop(30));
    mixSlider.setBounds(mixArea);

    outputLabel.setBounds(row.removeFromTop(30));
    outputSlider.setBounds(row);
}
