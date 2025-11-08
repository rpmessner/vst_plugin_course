#pragma once
#include <JuceHeader.h>

class SkeletonProcessor : public juce::AudioProcessor {
public:
  SkeletonProcessor();
  ~SkeletonProcessor() override = default;

  // AudioProcessor overrides
  void prepareToPlay(double sampleRate, int blockSize) override;
  void releaseResources() override;
  bool isBusesLayoutSupported(const BusesLayout &layout) const override;
  void processBlock(juce::AudioBuffer<float> &, juce::MidiBuffer &) override;

  // Editor
  bool hasEditor() const override { return false; } // no GUI yet
  AudioProcessorEditor *createEditor() override { return nullptr; }

  // Presets
  const juce::String getName() const override { return JucePlugin_Name; }
  bool acceptsMidi() const override { return true; }
  bool producesMidi() const override { return true; }
  double getTailLengthSeconds() const override { return 0.0; }
  int getNumPrograms() override { return 1; }
  int getCurrentProgram() override { return 0; }
  void setCurrentProgram(int) override {}
  const juce::String getProgramName(int) override { return {}; }
  void changeProgramName(int, const juce::String &) override {}

  // State
  void getStateInformation(juce::MemoryBlock &data) override;
  void setStateInformation(const void *data, int sizeInBytes) override;

private:
  JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(SkeletonProcessor)
};
