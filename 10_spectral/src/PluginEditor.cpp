#include "PluginEditor.h"

SpectralPluginEditor::SpectralPluginEditor(SpectralPluginProcessor &p)
    : AudioProcessorEditor(&p), audioProcessor(p) {
    setSize(400, 400);

    // FFT Size slider
    fftSizeSlider.setSliderStyle(juce::Slider::RotaryHorizontalVerticalDrag);
    fftSizeSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 80, 20);
    fftSizeSlider.setTextValueSuffix("");
    addAndMakeVisible(fftSizeSlider);
    fftSizeLabel.setText("FFT Size", juce::dontSendNotification);
    fftSizeLabel.setJustificationType(juce::Justification::centred);
    addAndMakeVisible(fftSizeLabel);
    fftSizeAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(
        audioProcessor.getValueTreeState(), "fftSize", fftSizeSlider);

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
}

SpectralPluginEditor::~SpectralPluginEditor() {}

void SpectralPluginEditor::paint(juce::Graphics &g) {
    g.fillAll(juce::Colours::darkgrey);
}

void SpectralPluginEditor::resized() {
    auto area = getLocalBounds().reduced(20);

    fftSizeLabel.setBounds(area.removeFromTop(30));
    fftSizeSlider.setBounds(area.removeFromTop(120));

    thresholdLabel.setBounds(area.removeFromTop(30));
    thresholdSlider.setBounds(area.removeFromTop(120));
}
