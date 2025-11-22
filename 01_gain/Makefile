BUILD_DIR := build
CONFIG := Release
CMAKE_GENERATOR := Ninja
STRICTNESS := 5
PLUGIN_VAL := pluginval
PLUGIN_NAME := GainPlugin
ARTEFACTS_PATH = $(BUILD_DIR)/$(PLUGIN_NAME)_artefacts
PLUGIN_PATH = "$(ARTEFACTS_PATH)/Release/VST3/$(PLUGIN_NAME).vst3"

.PHONY: all configure vst3 test clean

all: vst3

configure:
	cmake -B $(BUILD_DIR) -G "$(CMAKE_GENERATOR)" -DCMAKE_BUILD_TYPE=$(CONFIG)

vst3: configure
	ninja -C $(BUILD_DIR)

test: vst3
	@echo "Testing plugin..."
	$(PLUGIN_VAL) --strictness-level $(STRICTNESS) --validate $(PLUGIN_PATH)
	@echo "All tests passed!"

clean:
	rm -rf $(BUILD_DIR)
