# GENERAL RESEARCH
A brain dump of what I am learning for this project. Refer to the **GENERAL RESEARCH CITATIONS IEEE** for the works cited.

## 1. Fundamentals (Information from [1] unless otherwise cited)

### What is EMG?
EMG stands for **Electromyography**. This is a signal that represents the electrical potentials (V) in muscles when they contract, which is always controlled by the nervous system. EMG signals tend to be noisy, being distorted by: 
- tissues
- other moving muscles

This affects the output potentials read on electrodes. 

There have been many advancements in creating algorithms and hardware interfaces that use EMG signals for things like prosthetics, activating devices, or general medical tracking and diagnosis support.

It is common to hear terms like "myoelectric activity" or "myographic action potential" in reference to EMG.

*A note from the paper:*
>The combination of the muscle fiber action potentials from all the muscle fibers of a single motor unit is the motor unit action potential (MUAP) which can be detected by a skin surface electrode (non-invasive)

Although humans are electrically neutral, the nerve cell membrane is not. In its resting state, it's membrane is polarized since the concentrations of the plasma membrane and that of ions is not homogeneous throughout the cell. The paper explains how this creates EMG signals: 
>A potential difference exists between the intra-cellular and extracellular fluids of the cell. In response to a stimulus from the neuron, a muscle fiber depolarizes [where the potential flips due to the stimulus from the neuron's action potential signal (thanks Claude!)] as the signal propagates along its surface and the fiber twitches. This depolarization, accompanied by a movement of [cat]ions, generates an electric field near each muscle fiber [like in a capacitor!]. An EMG signal is the train of [MUAPs] showing the muscle response to neural stimulation. 

### Why? And what do these signals tell us?
EMG signals are of importance nowadays, since they help with understanding movements and in physical rehab. Furthermore, the "shapes and firing rates of Motor Unit Action Potentials (MUAPs)" help in determining and understanding neuromuscular disorders. 

*A note from the paper:*
>When EMG is acquired from electrodes mounted directly on the skin, the signal is a composite of all the muscle fiber action potentials occurring in the muscles underlying the skin. These action potentials occur at random intervals. So at any one moment, the EMG signal may be either positive or negative voltage.

### Signal stats and considerations [4]
- Prior to amplifying, EMG signals tend to have a peak-to-peak amplitude of 0-10 mV (which corresponds to ± 5 mV = ± 0.005 V)
- Domain frequency of the dominant EMG signal lies between 50-150 Hz
- Given the above tendencies for the dominant signal, EMG inputs are typically filtered from ranges such as 5-500 Hz and 20-300 Hz. This gives leeway for how some signals do tend to be shown at higher or lower frequencies than the average dominant signal. 
    - Also, I feel like different parts of the body likely produce different frequencies for EMG signals, so this might be something worth considering in terms of how wide the bandpass filter window should be 

### How do people get usable data out of these tiny signals?
Amplifying these signals is **imperative** for getting real outputs. Typically, multiple amplification and filtering stages are applied to get clean data. Commonly, using **differential amplifiers** helps exaggerate the difference in the MUAPs, which is more telling of when a contraction occurs. 

Also, **instrumental amplifiers** like the INA333 are used, typically after a preamplification stage. However, LLMs tend to disagree on the ordering of the instrumental amplifiers with respect to the first standalone amplification stage, so ordering seems like something to determine experimentally. 

In conjunction with these stages, a mediative bandpass filter is typically applied to reject very low and very high frequencies out of the picture.

Here is a differential amplifier. Typically, R1=R2 and R3=R4, yielding an amplification equation of [2]:

$$
U_{a} = \frac{R_2}{R_1}(U_{e+} - U_{e-})
$$ 

![Differential Amplifier](media/differential_amp.png)
[3]

### Things that affect the signal
When detecting EMG signals from the surface, like in the dry electrode application, there are a few considerations for the clarity of outputs. Holistically, signal-to-noise ratio has an impact. Essentially, how much energy the EMG signal we care about produces vs. things external to the signal like powerline interference. Further, the distortion of the signal also skews results. This can come from other MUAPs, tissues altering the signal, etc.

Some common interferences:
1. *Noise in the circuits or tools used.* Ensuring that the components are high quality and don't reduce, resist, or otherwise distort the readable signals is a must. 
2. *Ambient noise.* Electromagnetic radiation causes this, and our skin is always being hit with this. We can't escape sources like light, heat, radio signals, etc. 
    >The ambient noise may have amplitude that is one to three orders of magnitude greater than the EMG signal.
3. *Motion artifacts.* Unwanted movements in other areas of the body, or even nearby (potentially as a result of the action that is being measured by EMG) can skew the data being collected. Motion artifacts also refer to the distortions caused by shifting from the surface electrodes and wire movement.

## 2. Tools Needed
WIP
