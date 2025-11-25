#include "PluginEditor.h"

FilterPluginEditor::FilterPluginEditor(FilterPluginProcessor &p)
    : AudioProcessorEditor(&p), audioProcessor(p) {
    setSize(400, 400);

    // Filter Type combo
    filterTypeCombo.addItem("Low Pass", 1);
    filterTypeCombo.addItem("High Pass", 2);
    filterTypeCombo.addItem("Band Pass", 3);
    addAndMakeVisible(filterTypeCombo);
    filterTypeLabel.setText("Filter Type", juce::dontSendNotification);
    filterTypeLabel.setJustificationType(juce::Justification::centredLeft);
    addAndMakeVisible(filterTypeLabel);
    filterTypeAttachment = std::make_unique<juce::AudioProcessorValueTreeState::ComboBoxAttachment>(
        audioProcessor.getValueTreeState(), "filterType", filterTypeCombo);

    // Cutoff slider
    cutoffSlider.setSliderStyle(juce::Slider::RotaryHorizontalVerticalDrag);
    cutoffSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 80, 20);
    cutoffSlider.setTextValueSuffix(" Hz");
    addAndMakeVisible(cutoffSlider);
    cutoffLabel.setText("Cutoff", juce::dontSendNotification);
    cutoffLabel.setJustificationType(juce::Justification::centred);
    addAndMakeVisible(cutoffLabel);
    cutoffAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(
        audioProcessor.getValueTreeState(), "cutoff", cutoffSlider);

    // Resonance slider
    resonanceSlider.setSliderStyle(juce::Slider::RotaryHorizontalVerticalDrag);
    resonanceSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 80, 20);
    addAndMakeVisible(resonanceSlider);
    resonanceLabel.setText("Resonance", juce::dontSendNotification);
    resonanceLabel.setJustificationType(juce::Justification::centred);
    addAndMakeVisible(resonanceLabel);
    resonanceAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(
        audioProcessor.getValueTreeState(), "resonance", resonanceSlider);
}

FilterPluginEditor::~FilterPluginEditor() {}

void FilterPluginEditor::paint(juce::Graphics &g) {
    g.fillAll(juce::Colours::darkgrey);
}

void FilterPluginEditor::resized() {
    auto area = getLocalBounds().reduced(20);

    auto comboArea = area.removeFromTop(60);
    filterTypeLabel.setBounds(comboArea.removeFromTop(25));
    filterTypeCombo.setBounds(comboArea);

    area.removeFromTop(10);

    auto row = area.removeFromTop(150);
    auto cutoffArea = row.removeFromLeft(getWidth() / 2);

    cutoffLabel.setBounds(cutoffArea.removeFromTop(30));
    cutoffSlider.setBounds(cutoffArea);

    resonanceLabel.setBounds(row.removeFromTop(30));
    resonanceSlider.setBounds(row);
}
