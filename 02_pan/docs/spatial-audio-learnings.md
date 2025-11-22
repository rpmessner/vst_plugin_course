# Spatial Audio Learnings

## Panning Laws

### Linear Panning
- **Implementation**: Simple linear interpolation between channels
- **Formula**: `L = (1-pan)/2`, `R = (1+pan)/2`
- **Pros**: Simple, predictable
- **Cons**: Perceived loudness dip in center (about -3dB)

### Constant-Power Panning
- **Implementation**: Uses trigonometric functions
- **Formula**: `L = cos(pan * π/4)`, `R = sin(pan * π/4)`
- **Pros**: Maintains constant perceived loudness across pan range
- **Cons**: Slightly more CPU intensive

### Comparison
| Position | Linear (dB) | Constant-Power (dB) |
|----------|-------------|---------------------|
| Left     | 0           | 0                   |
| Center   | -3          | 0                   |
| Right    | 0           | 0                   |

## Stereo Field Concepts

### Stereo Width
- Controls the separation between left and right channels
- Width = 0: mono, Width = 1: normal stereo, Width > 1: enhanced stereo

### Phase Correlation
- Measures the similarity between left and right channels
- +1 = perfectly in phase, 0 = uncorrelated, -1 = perfectly out of phase

## References
- JUCE `dsp::Panner` class
- "The Art of Mixing" by David Gibson
