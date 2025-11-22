# VST Plugin Development Project

## Project Overview

This project develops 10 fundamental VST plugins to test and demonstrate core
audio processing categories. Each plugin is built using JUCE framework and CMake,
serving as both learning exercises and practical audio processing tools.

## Project Structure

- Each plugin in its own numbered directory (e.g., `00_skeleton/`, `01_gain/`)
- JUCE framework managed as git submodule in `vendor/juce/`
- Shared build configuration via CMake
- Common structure: `src/`, `CMakeLists.txt`, plugin-specific assets

## 10 Fundamental Plugin Categories

1. **00_skeleton** - Basic plugin template (currently implemented)
2. **01_gain** - Amplitude/volume control
3. **02_filter** - EQ and filtering (low-pass, high-pass, band-pass)
4. **03_dynamics** - Compression, limiting, gating
5. **04_modulation** - Chorus, flanger, phaser, tremolo
6. **05_delay** - Delay effects and echo
7. **06_reverb** - Spatial/ambience effects
8. **07_distortion** - Saturation, overdrive, clipping
9. **08_pitch** - Pitch shifting and time stretching
10. **09_analysis** - Metering, visualization, spectrum analysis

## Build System

- **Framework**: JUCE (submodule)
- **Build tool**: CMake
- **Target formats**: VST3, AU, Standalone
- **C++ Standard**: Modern C++ (configured per JUCE requirements)

## Development Notes

- Start from `00_skeleton/` as base template
- Each plugin inherits from `juce::AudioProcessor`
- UI built with `juce::AudioProcessorEditor`
- Parameter management via JUCE's parameter system
- DSP processing in `processBlock()`

## Current Status

- ✓ Skeleton template established
- → Ready to implement individual plugins

## Key Files Per Plugin

- `src/PluginProcessor.h/cpp` - Audio processing logic
- `src/PluginEditor.h/cpp` - UI components
- `CMakeLists.txt` - Build configuration
