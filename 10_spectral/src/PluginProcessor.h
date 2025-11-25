#pragma once
#include <JuceHeader.h>

class SpectralPluginProcessor : public juce::AudioProcessor {
public:
    SpectralPluginProcessor();
    ~SpectralPluginProcessor() override;

    void prepareToPlay(double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;
    void processBlock(juce::AudioBuffer<float> &, juce::MidiBuffer &) override;

    juce::AudioProcessorEditor *createEditor() override;
    bool hasEditor() const override { return true; }

    const juce::String getName() const override { return "SpectralPlugin"; }
    bool acceptsMidi() const override { return false; }
    bool producesMidi() const override { return false; }
    double getTailLengthSeconds() const override { return 0.0; }

    int getNumPrograms() override { return 1; }
    int getCurrentProgram() override { return 0; }
    void setCurrentProgram(int) override {}
    const juce::String getProgramName(int) override { return "Default"; }
    void changeProgramName(int, const juce::String &) override {}

    void getStateInformation(juce::MemoryBlock &) override;
    void setStateInformation(const void *, int) override;

    juce::AudioProcessorValueTreeState &getValueTreeState() { return parameters; }

private:
    juce::AudioProcessorValueTreeState parameters;
    std::atomic<float> *fftSizeParam = nullptr;
    std::atomic<float> *thresholdParam = nullptr;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(SpectralPluginProcessor)
};
