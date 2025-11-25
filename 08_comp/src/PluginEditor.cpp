#include "PluginEditor.h"

CompressorPluginEditor::CompressorPluginEditor(CompressorPluginProcessor &p)
    : AudioProcessorEditor(&p), audioProcessor(p) {
    setSize(400, 640);

    // Threshold slider
    thresholdSlider.setSliderStyle(juce::Slider::RotaryHorizontalVerticalDrag);
    thresholdSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 80, 20);
    thresholdSlider.setTextValueSuffix(" dB");
    addAndMakeVisible(thresholdSlider);
    thresholdLabel.setText("Threshold", juce::dontSendNotification);
    thresholdLabel.setJustificationType(juce::Justification::centred);
    addAndMakeVisible(thresholdLabel);
    thresholdAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(
        audioProcessor.getValueTreeState(), "threshold", thresholdSlider);

    // Ratio slider
    ratioSlider.setSliderStyle(juce::Slider::RotaryHorizontalVerticalDrag);
    ratioSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 80, 20);
    ratioSlider.setTextValueSuffix(":1");
    addAndMakeVisible(ratioSlider);
    ratioLabel.setText("Ratio", juce::dontSendNotification);
    ratioLabel.setJustificationType(juce::Justification::centred);
    addAndMakeVisible(ratioLabel);
    ratioAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(
        audioProcessor.getValueTreeState(), "ratio", ratioSlider);

    // Attack slider
    attackSlider.setSliderStyle(juce::Slider::RotaryHorizontalVerticalDrag);
    attackSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 80, 20);
    attackSlider.setTextValueSuffix(" ms");
    addAndMakeVisible(attackSlider);
    attackLabel.setText("Attack", juce::dontSendNotification);
    attackLabel.setJustificationType(juce::Justification::centred);
    addAndMakeVisible(attackLabel);
    attackAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(
        audioProcessor.getValueTreeState(), "attack", attackSlider);

    // Release slider
    releaseSlider.setSliderStyle(juce::Slider::RotaryHorizontalVerticalDrag);
    releaseSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 80, 20);
    releaseSlider.setTextValueSuffix(" ms");
    addAndMakeVisible(releaseSlider);
    releaseLabel.setText("Release", juce::dontSendNotification);
    releaseLabel.setJustificationType(juce::Justification::centred);
    addAndMakeVisible(releaseLabel);
    releaseAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(
        audioProcessor.getValueTreeState(), "release", releaseSlider);
}

CompressorPluginEditor::~CompressorPluginEditor() {}

void CompressorPluginEditor::paint(juce::Graphics &g) {
    g.fillAll(juce::Colours::darkgrey);
}

void CompressorPluginEditor::resized() {
    auto area = getLocalBounds().reduced(20);

    thresholdLabel.setBounds(area.removeFromTop(30));
    thresholdSlider.setBounds(area.removeFromTop(120));

    ratioLabel.setBounds(area.removeFromTop(30));
    ratioSlider.setBounds(area.removeFromTop(120));

    attackLabel.setBounds(area.removeFromTop(30));
    attackSlider.setBounds(area.removeFromTop(120));

    releaseLabel.setBounds(area.removeFromTop(30));
    releaseSlider.setBounds(area.removeFromTop(120));
}
