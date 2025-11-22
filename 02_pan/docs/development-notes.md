# Pan Plugin Development Notes

## Overview
Simple stereo panning plugin implementing linear panning law.

## Implementation Details

### Panning Law
- Uses **linear panning law** for simplicity
- Pan range: -1.0 (full left) to +1.0 (full right)
- Center position (0.0) gives equal amplitude to both channels

### Formula
```cpp
leftGain = (1.0 - pan) * 0.5
rightGain = (1.0 + pan) * 0.5
```

### Parameter Smoothing
- 50ms smoothing time to avoid zipper noise
- Uses JUCE's LinearSmoothedValue

## Future Improvements
- Implement constant-power panning law for better perceived loudness
- Add stereo width control
- Visualize panning position in GUI
