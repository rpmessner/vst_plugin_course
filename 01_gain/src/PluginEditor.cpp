#include "PluginEditor.h"

GainPluginEditor::GainPluginEditor(GainPluginProcessor &p)
    : AudioProcessorEditor(&p), audioProcessor(p) {
    setSize(400, 300);

    // Gain slider
    gainSlider.setSliderStyle(juce::Slider::RotaryHorizontalVerticalDrag);
    gainSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 80, 20);
    gainSlider.setTextValueSuffix(" dB");
    addAndMakeVisible(gainSlider);

    // Gain label
    gainLabel.setText("Gain", juce::dontSendNotification);
    gainLabel.setJustificationType(juce::Justification::centred);
    addAndMakeVisible(gainLabel);

    // Attach slider to parameter
    gainAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(
        audioProcessor.getValueTreeState(), "gain", gainSlider);
}

GainPluginEditor::~GainPluginEditor() {}

void GainPluginEditor::paint(juce::Graphics &g) {
    g.fillAll(juce::Colours::darkgrey);
}

void GainPluginEditor::resized() {
    auto area = getLocalBounds().reduced(20);

    gainLabel.setBounds(area.removeFromTop(30));
    gainSlider.setBounds(area.removeFromTop(150));
}
