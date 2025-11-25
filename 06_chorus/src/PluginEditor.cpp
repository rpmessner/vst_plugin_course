#include "PluginEditor.h"

ChorusPluginEditor::ChorusPluginEditor(ChorusPluginProcessor &p)
    : AudioProcessorEditor(&p), audioProcessor(p) {
    setSize(400, 480);

    // Rate slider
    rateSlider.setSliderStyle(juce::Slider::RotaryHorizontalVerticalDrag);
    rateSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 80, 20);
    rateSlider.setTextValueSuffix(" Hz");
    addAndMakeVisible(rateSlider);
    rateLabel.setText("Rate", juce::dontSendNotification);
    rateLabel.setJustificationType(juce::Justification::centred);
    addAndMakeVisible(rateLabel);
    rateAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(
        audioProcessor.getValueTreeState(), "rate", rateSlider);

    // Depth slider
    depthSlider.setSliderStyle(juce::Slider::RotaryHorizontalVerticalDrag);
    depthSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 80, 20);
    depthSlider.setTextValueSuffix("");
    addAndMakeVisible(depthSlider);
    depthLabel.setText("Depth", juce::dontSendNotification);
    depthLabel.setJustificationType(juce::Justification::centred);
    addAndMakeVisible(depthLabel);
    depthAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(
        audioProcessor.getValueTreeState(), "depth", depthSlider);

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

ChorusPluginEditor::~ChorusPluginEditor() {}

void ChorusPluginEditor::paint(juce::Graphics &g) {
    g.fillAll(juce::Colours::darkgrey);
}

void ChorusPluginEditor::resized() {
    auto area = getLocalBounds().reduced(20);

    rateLabel.setBounds(area.removeFromTop(30));
    rateSlider.setBounds(area.removeFromTop(120));

    depthLabel.setBounds(area.removeFromTop(30));
    depthSlider.setBounds(area.removeFromTop(120));

    mixLabel.setBounds(area.removeFromTop(30));
    mixSlider.setBounds(area.removeFromTop(120));
}
