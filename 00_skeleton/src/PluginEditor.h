#pragma once
#include <JuceHeader.h>
class MinimalPluginAudioProcessor;

class MinimalPluginAudioEditor : public juce::AudioProcessorEditor {
public:
  explicit MinimalPluginAudioEditor(MinimalPluginAudioProcessor &);
  ~MinimalPluginAudioEditor() override;

  void paint(juce::Graphics &) override;
  void resized() override;

private:
  MinimalPluginAudioProcessor &audioProcessor;
};
