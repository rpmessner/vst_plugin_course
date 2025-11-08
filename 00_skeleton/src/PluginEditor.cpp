#include "PluginEditor.h"
#include "PluginProcessor.h"

MinimalPluginAudioEditor::MinimalPluginAudioEditor(
    MinimalPluginAudioProcessor &p)
    : AudioProcessorEditor(&p), audioProcessor(p) {
  setSize(400, 300);
}

MinimalPluginAudioEditor::~MinimalPluginAudioEditor() {}

void MinimalPluginAudioEditor::paint(juce::Graphics &g) {
  g.fillAll(
      getLookAndFeel().findColour(juce::ResizableWindow::backgroundColourId));
  g.setColour(juce::Colours::white);
  g.setFont(15.0f);
  g.drawFittedText("Minimal VST3 Plugin", getLocalBounds(),
                   juce::Justification::centred, 1);
}

void MinimalPluginAudioEditor::resized() {}
