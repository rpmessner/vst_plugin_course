cmake_minimum_required(VERSION 3.20)
project(Skeleton VERSION 0.0.1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# ---- JUCE ----
include(FetchContent)
FetchContent_Declare(
    JUCE
    GIT_REPOSITORY https://github.com/juce-framework/JUCE.git
    GIT_TAG 8.0.10
)
FetchContent_MakeAvailable(JUCE)
juce_add_plugin(Skeleton
        VERSION 1.0.0
        COMPANY_NAME "Demo"
        IS_SYNTH FALSE
        NEEDS_MIDI_INPUT TRUE
        NEEDS_MIDI_OUTPUT TRUE
        IS_MIDI_EFFECT TRUE
        FORMATS VST3
        PLUGIN_MANUFACTURER_CODE Demo
        PLUGIN_CODE Sklt
        PRODUCT_NAME "Skeleton"
        BUNDLE_ID "com.demo.skeleton"
        PLUGIN_NAME "Plugin Skeleton"
        PRODUCT_NAME "Plugin Skeleton")

juce_generate_juce_header(Skeleton)

target_compile_features(Skeleton PRIVATE cxx_std_17)

target_sources(Skeleton
        PRIVATE
                src/PluginEditor.cpp
                src/PluginProcessor.cpp)

target_link_libraries(Skeleton
        PRIVATE
                juce::juce_audio_processors
                juce::juce_audio_utils
                juce::juce_audio_plugin_client
                juce::juce_dsp
        PUBLIC
                juce::juce_recommended_config_flags
                juce::juce_recommended_lto_flags
                juce::juce_recommended_warning_flags)

target_compile_definitions(Skeleton
        PUBLIC
                JUCE_WEB_BROWSER=0
                JUCE_USE_CURL=0
                JUCE_VST3_CAN_REPLACE_VST2=0)

