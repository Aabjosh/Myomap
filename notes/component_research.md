# COMPONENT RESEARCH
This piggybacks off of my **GENERAL RESEARCH**, where I'm writing down what the components I intend to use are, and how they work (to my understanding).

## INA333 [1]
Low-Power, Zero-Drift, Precision Instrumentation Amplifier. Essentially a differential amp but better because it has CMRR to filter out things like powerline interference!! Another amp stage will most likely need to be used since this doesn't really boost the signal diff that much, but cleans it up quite a bit.
- Built using 3 op amps
- An external resistor (or potentiometer on the board), R_G, allows a gain, G, from 1-1000x to be set
    - $G = 1 + \frac{100\,\mathrm{k\Omega}}{R_{G}}$
- Low offset voltage (25 μV, G ≥ 100)
    >This is the deviation from ideal behaviour, where a perfect amp would have 0v at its output terminal for equal inverting and non-inverting inputs [Claude]
- The random noise of the amp varies with the square root of the bandwidth for the signal, multiplied by 50 nV (rms), so it is relatively very low
- CMRR (or, Common Mode Rejection) is at 100 dB, meaning patterns like the 60 hz AC variation are cut by 100000x [Claude is very helpful]
    >CMRR is the ratio of how much the amplifier amplifies a wanted difference signal to how much it amplifies an unwanted common-mode signal (like mains hum) -> Differential Noise / Common Noise
    - $dB = 20\log(ratio \ of \ signals)$
- The device seems to **barely disrupt the signals coming in and going out**, only pulling 200 pA on the input pins, and small variances of fractions of a volt for the input and output bias voltages relative to the supply voltage
    - Also only takes **50 µA when idle!!** That's pretty awesome for our portable application :)
- Note that **adding capacitors to the power rail junctions (connected to ground)** allows for a steady input (shown in TI's examples), shunting the noise to ground. Think of it like a bouncer, who notices outliers and throws them away. As part of a junction to the rails, a capacitor that goes to ground acts like an open circuit when there's steady current (it's electric field is saturated so no more electrons travel through it) until a frequency is introduced, fluctuating the field and allowing more electrons to flow through when noisy (proportional to the frequency).
- Low impedance at the reference is **necessary to preserve CMRR**, so if impedance is high, a buffer opamp is used to slam the impedance and produce a less restricted signal
    >This pin is typically grounded, but even for some of the benchmarks a common reference is half of the supply voltage range. This is because the output is [simplified by Claude]: $V_{OUT} = Gain(V_{IN+} - V_{IN-}) + V_{REF}$, so having the entire waveform requires the negative fluctuations to still be shown. For simple applications like the intended use case for this project, grounding this pin is acceptable since the waveform existing even in its half-murdered form is indicative of movement, but if we want to do analysis on the waveform, it is probably best to set this pin to half of the input range, preserving all of the signal. 
