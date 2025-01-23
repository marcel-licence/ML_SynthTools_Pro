/*
 * ML SynthTools Pro - A modular synthesizer library including organ, electric piano,
 * oscillators, and sound synthesis tools.
 *
 * Copyright (C) 2025 Marcel Licence
 *
 * This file is part of the ML SynthTools Pro library and is licensed under the ML SynthTools Lib License.
 *
 * You may use this file in non-commercial projects, provided that this header
 * and all authorship attributions remain intact.
 *
 * For commercial use, please contact marcel.licence.o@gmail.com for licensing terms.
 *
 * The source code of this library is not included. Reverse-engineering,
 * decompiling, or any attempt to access the source code from the compiled files
 * is strictly prohibited.
 *
 * ML SynthTools Pro is provided "as is," without warranty of any kind. See the LICENSE
 * file for the full license text.
 */

/**
 * @file ml_oscillator_pro.h
 * @author Marcel Licence
 * @date 26.11.2021
 *
 * @brief   This is the improved version of the oscillator
 */


#ifndef SRC_ML_OSCILLATOR_PRO_H_
#define SRC_ML_OSCILLATOR_PRO_H_


#include <stdint.h>
#include <stdio.h>
#include <math.h>


/* controllable parameters, some of them might not work, but added in future */
#define SYNTH_PWM_OSC_PARAM_PULSE_WIDTH     17 /* offset of the pulse width */
#define SYNTH_PWM_OSC_PARAM_PULSE_LEVEL     18
#define SYNTH_PWM_OSC_PARAM_PULSE_MUL       19
#define SYNTH_PWM_OSC_PARAM_PULSE_MOD_DEPTH 20 /* intensity of the automated modulation */
#define SYNTH_PWM_OSC_PARAM_PULSE_MOD_SPEED 21 /* speed of the automated modulation */
#define SYNTH_PWM_OSC_PARAM_PULSE_OFFSET    22

/* useable waveforms for the main oscillator */
#define SYNTH_PWM_OSC_WAVEFORM_SAW    0
#define SYNTH_PWM_OSC_WAVEFORM_SAW_PWM    1
#define SYNTH_PWM_OSC_WAVEFORM_SQR_PWM    2


class ML_OscillatorPro
{
public:
    ML_OscillatorPro();

    /*
     * required to setup all oscillators
     */
    static void Setup(float sample_rate);

    void Start(uint32_t add);
    void Start(float *left, float *right, uint32_t add); /* Start oscillator with linked output */
    void Stop(void);
    void SetPitchMultiplier(float multiplier);

    void ProcessBuffer(float *left, float *right, int len);
    void ProcessBuffer(int len);

    bool isFree(void);
    bool isCon(void);
    bool isCon(const float *sig);

    /*
     * set parameter for all oscillators
     */
    static void SetParam(uint8_t osc_param, float value);
    static void SetWaveform(uint8_t *waveform_ptr);

private:

    uint32_t samplePos;
    uint32_t samplePosSub;
    uint32_t addVal;

    uint32_t lfo;

    float *dest[2];

    bool active;
};

#endif /* SRC_ML_OSCILLATOR_PRO_H_ */

