#include "PluginEditor.h"

ReverbPluginEditor::ReverbPluginEditor(ReverbPluginProcessor &p)
    : AudioProcessorEditor(&p), audioProcessor(p) {
    setSize(400, 480);

    // Room Size slider
    roomSizeSlider.setSliderStyle(juce::Slider::RotaryHorizontalVerticalDrag);
    roomSizeSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 80, 20);
    roomSizeSlider.setTextValueSuffix("");
    addAndMakeVisible(roomSizeSlider);
    roomSizeLabel.setText("Room Size", juce::dontSendNotification);
    roomSizeLabel.setJustificationType(juce::Justification::centred);
    addAndMakeVisible(roomSizeLabel);
    roomSizeAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(
        audioProcessor.getValueTreeState(), "roomSize", roomSizeSlider);

    // Damping slider
    dampingSlider.setSliderStyle(juce::Slider::RotaryHorizontalVerticalDrag);
    dampingSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 80, 20);
    dampingSlider.setTextValueSuffix("");
    addAndMakeVisible(dampingSlider);
    dampingLabel.setText("Damping", juce::dontSendNotification);
    dampingLabel.setJustificationType(juce::Justification::centred);
    addAndMakeVisible(dampingLabel);
    dampingAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(
        audioProcessor.getValueTreeState(), "damping", dampingSlider);

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

ReverbPluginEditor::~ReverbPluginEditor() {}

void ReverbPluginEditor::paint(juce::Graphics &g) {
    g.fillAll(juce::Colours::darkgrey);
}

void ReverbPluginEditor::resized() {
    auto area = getLocalBounds().reduced(20);

    roomSizeLabel.setBounds(area.removeFromTop(30));
    roomSizeSlider.setBounds(area.removeFromTop(120));

    dampingLabel.setBounds(area.removeFromTop(30));
    dampingSlider.setBounds(area.removeFromTop(120));

    mixLabel.setBounds(area.removeFromTop(30));
    mixSlider.setBounds(area.removeFromTop(120));
}
