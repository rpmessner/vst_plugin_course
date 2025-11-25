cmake_minimum_required(VERSION 3.22)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(PitchPlugin VERSION 1.0.0)

add_subdirectory(vendor/juce)

juce_add_plugin(PitchPlugin
    COMPANY_NAME "Demo"
    BUNDLE_ID "com.demo.pitch_plugin"
    IS_SYNTH FALSE
    IS_MIDI_EFFECT FALSE
    PLUGIN_MANUFACTURER_CODE Demo
    PLUGIN_CODE Ptch
    FORMATS VST3 Standalone
    PRODUCT_NAME "PitchPlugin")

juce_generate_juce_header(PitchPlugin)
target_include_directories(PitchPlugin PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)
add_subdirectory(src)

target_compile_definitions(PitchPlugin
    PUBLIC
        JUCE_WEB_BROWSER=0
        JUCE_USE_CURL=0
        JUCE_VST3_CAN_REPLACE_VST2=0)

target_link_libraries(PitchPlugin
    PRIVATE
        juce::juce_audio_utils
        juce::juce_dsp
    PUBLIC
        juce::juce_recommended_config_flags
        juce::juce_recommended_lto_flags
        juce::juce_recommended_warning_flags)
