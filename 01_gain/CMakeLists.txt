cmake_minimum_required(VERSION 3.22)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(GainPlugin VERSION 1.0.0)

# Add JUCE from submodule
add_subdirectory(vendor/juce)

# Define the plugin
juce_add_plugin(GainPlugin
    COMPANY_NAME "Demo"
    BUNDLE_ID "com.demo.gain_plugin"
    IS_SYNTH FALSE
    IS_MIDI_EFFECT FALSE
    PLUGIN_MANUFACTURER_CODE Demo
    PLUGIN_CODE Gain
    FORMATS VST3 Standalone
    PRODUCT_NAME "GainPlugin")

# Generate JuceHeader.h
juce_generate_juce_header(GainPlugin)

# Add include directory
target_include_directories(GainPlugin PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src)

# Add source files
add_subdirectory(src)

# Set compile definitions
target_compile_definitions(GainPlugin
    PUBLIC
        JUCE_WEB_BROWSER=0
        JUCE_USE_CURL=0
        JUCE_VST3_CAN_REPLACE_VST2=0)

# Link JUCE modules
target_link_libraries(GainPlugin
    PRIVATE
        juce::juce_audio_utils
        juce::juce_dsp
    PUBLIC
        juce::juce_recommended_config_flags
        juce::juce_recommended_lto_flags
        juce::juce_recommended_warning_flags)
