BUILD_DIR := build
CONFIG := Release
CMAKE_GENERATOR := Ninja
PLUGIN_NAME := ReverbPlugin

.PHONY: all configure vst3 clean

all: vst3

configure:
	cmake -B $(BUILD_DIR) -G "$(CMAKE_GENERATOR)" -DCMAKE_BUILD_TYPE=$(CONFIG)

vst3: configure
	ninja -C $(BUILD_DIR)

clean:
	rm -rf $(BUILD_DIR)
