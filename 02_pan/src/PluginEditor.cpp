#include "PluginEditor.h"

PanPluginEditor::PanPluginEditor(PanPluginProcessor &p)
    : AudioProcessorEditor(&p), audioProcessor(p) {
    setSize(400, 300);

    // Pan slider
    panSlider.setSliderStyle(juce::Slider::RotaryHorizontalVerticalDrag);
    panSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 80, 20);
    addAndMakeVisible(panSlider);

    // Pan label
    panLabel.setText("Pan", juce::dontSendNotification);
    panLabel.setJustificationType(juce::Justification::centred);
    addAndMakeVisible(panLabel);

    // Attach slider to parameter
    panAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(
        audioProcessor.getValueTreeState(), "pan", panSlider);
}

PanPluginEditor::~PanPluginEditor() {}

void PanPluginEditor::paint(juce::Graphics &g) {
    g.fillAll(juce::Colours::darkgrey);
}

void PanPluginEditor::resized() {
    auto area = getLocalBounds().reduced(20);

    panLabel.setBounds(area.removeFromTop(30));
    panSlider.setBounds(area.removeFromTop(150));
}
