# Image Dither & Error Diffusion
I’ve done 5 game jams, and every time, I find myself staring at shaders. This project is me taking that interest and digging into the Digital Signal Processing (DSP) side of graphics.

Basically, I’m treating an image like a signal and dealing with Quantization Error—the "noise" you get when you try to cram a high-res signal into a tiny, low-bit palette.
# Implementation
1. Error Diffusion (Feedback Loops)

This isn't just "picking the closest color." When the code picks a palette color, it calculates the Euclidean distance (the error) between the original pixel and the new one.

Instead of throwing that data away, I treat it like a signal feedback loop and "leak" that error into the neighboring pixels.

- The Result: You get those classic organic "clouds" of dots that preserve gradients even on a 1-bit display.

2. Bayer Matrix (The PWM Approach)

This is the "Electronics" way of doing things. It works like Pulse Width Modulation (PWM) for your eyes. By using a static threshold matrix (Bayer), I can decide which pixels fire "high" or "low."

It creates that rigid, cross-hatched "GameBoy" look because the pattern is periodic, not randomized.

