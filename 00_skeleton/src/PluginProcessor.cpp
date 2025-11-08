#include "PluginProcessor.h"

SkeletonProcessor::SkeletonProcessor()
    : AudioProcessor(
          BusesProperties()
              .withInput("Input", juce::AudioChannelSet::stereo(), true)
              .withOutput("Output", juce::AudioChannelSet::stereo(), true)) {}

bool SkeletonProcessor::isBusesLayoutSupported(
    const BusesLayout &layouts) const {
  return layouts.getMainOutputChannelSet() == juce::AudioChannelSet::stereo();
}

void SkeletonProcessor::prepareToPlay(double sampleRate, int samplesPerBlock) {
  // Pre-allocate anything here later
  juce::ignoreUnused(sampleRate, samplesPerBlock);
}

void SkeletonProcessor::releaseResources() {
  // Free big buffers here later
}

void SkeletonProcessor::processBlock(juce::AudioBuffer<float> &buffer,
                                     juce::MidiBuffer &midiMessages) {
  juce::ScopedNoDenormals noDenormals;
  auto totalNumInputChannels = getTotalNumInputChannels();
  auto totalNumOutputChannels = getTotalNumOutputChannels();

  // Clear any output channels that didn't have an input
  for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
    buffer.clear(i, 0, buffer.getNumSamples());

  // PASS-THROUGH (zero DSP for skeleton)
  for (int channel = 0; channel < totalNumInputChannels; ++channel) {
    auto *inData = buffer.getReadPointer(channel);
    auto *outData = buffer.getWritePointer(channel);
    juce::FloatVectorOperations::copy(outData, inData, buffer.getNumSamples());
  }
}

void SkeletonProcessor::getStateInformation(juce::MemoryBlock &destData) {
  // empty preset for now
  destData.setSize(0);
}

void SkeletonProcessor::setStateInformation(const void *data, int sizeInBytes) {
  juce::ignoreUnused(data, sizeInBytes);
}
