# COMPONENT RESEARCH
This piggybacks off of my **GENERAL RESEARCH**, where I'm writing down what the components I intend to use are, and how they work (to my understanding).

## INA333 [1]
Low-Power, Zero-Drift, Precision Instrumentation Amplifier
- Built using 3 op amps
- An external resistor (or potentiometer on the board), R_G, allows a gain, G, from 1-1000x to be set
    - $G = 1 + \frac{100\,\mathrm{k\Omega}}{R_{G}}$
- Low offset voltage (25 μV, G ≥ 100)
    >This is the deviation from ideal behaviour, where a perfect amp would have 0v at its output terminal for equal inverting and non-inverting inputs [Claude]
- 