#include "PluginEditor.h"

DelayPluginEditor::DelayPluginEditor(DelayPluginProcessor &p)
    : AudioProcessorEditor(&p), audioProcessor(p) {
    setSize(400, 400);

    // Delay Time slider
    delayTimeSlider.setSliderStyle(juce::Slider::RotaryHorizontalVerticalDrag);
    delayTimeSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 80, 20);
    delayTimeSlider.setTextValueSuffix(" ms");
    addAndMakeVisible(delayTimeSlider);
    delayTimeLabel.setText("Delay Time", juce::dontSendNotification);
    delayTimeLabel.setJustificationType(juce::Justification::centred);
    addAndMakeVisible(delayTimeLabel);
    delayTimeAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(
        audioProcessor.getValueTreeState(), "delayTime", delayTimeSlider);

    // Feedback slider
    feedbackSlider.setSliderStyle(juce::Slider::RotaryHorizontalVerticalDrag);
    feedbackSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 80, 20);
    addAndMakeVisible(feedbackSlider);
    feedbackLabel.setText("Feedback", juce::dontSendNotification);
    feedbackLabel.setJustificationType(juce::Justification::centred);
    addAndMakeVisible(feedbackLabel);
    feedbackAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(
        audioProcessor.getValueTreeState(), "feedback", feedbackSlider);

    // Mix slider
    mixSlider.setSliderStyle(juce::Slider::RotaryHorizontalVerticalDrag);
    mixSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 80, 20);
    addAndMakeVisible(mixSlider);
    mixLabel.setText("Mix", juce::dontSendNotification);
    mixLabel.setJustificationType(juce::Justification::centred);
    addAndMakeVisible(mixLabel);
    mixAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(
        audioProcessor.getValueTreeState(), "mix", mixSlider);
}

DelayPluginEditor::~DelayPluginEditor() {}

void DelayPluginEditor::paint(juce::Graphics &g) {
    g.fillAll(juce::Colours::darkgrey);
}

void DelayPluginEditor::resized() {
    auto area = getLocalBounds().reduced(20);

    delayTimeLabel.setBounds(area.removeFromTop(30));
    delayTimeSlider.setBounds(area.removeFromTop(120));

    auto row = area.removeFromTop(150);
    auto feedbackArea = row.removeFromLeft(getWidth() / 2);

    feedbackLabel.setBounds(feedbackArea.removeFromTop(30));
    feedbackSlider.setBounds(feedbackArea);

    mixLabel.setBounds(row.removeFromTop(30));
    mixSlider.setBounds(row);
}
