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
 * @file ml_organ_pro
 * @author Marcel Licence
 * @date 10.12.2021
 *
 * @brief   This shows you all available functions to use the organ library (pro demo version)
 *          The library is still in progress and will be updated in future
 *          It is just a demo and the limitation is that every minute the sound will turn of shortly
 *
 *          Actually only the ESP32, Teensy 4.1 is supported
 */


#ifndef SRC_ML_ORGAN_PRO_H_
#define SRC_ML_ORGAN_PRO_H_




#include <stdint.h>




/**
 * call this first before using the module to initialize it
 */
void OrganPro_Setup(float sample_rate);
void OrganPro_LeslSetup(void);

/**
 * when initialized you will get your audio samples from this function
 */
void OrganPro_Process_fl(float *out, int bufLen);
void Rotary_Process(float *left, float *right, const float *in, int bufLen);

/**
 * this functions are used to feed in the note on/off events
 */
void OrganPro_NoteOn(uint8_t ch __attribute__((unused)), uint8_t note, uint8_t vel __attribute__((unused)));
void OrganPro_NoteOff(uint8_t ch __attribute__((unused)), uint8_t note);

/**
 * finally you can control some settings with the following functions
 */
void OrganPro_PercussionSet(uint8_t setting);
void OrganPro_SetLeslCtrl(uint8_t val);
void OrganPro_SetCtrl(uint8_t id, float value);
void OrganPro_SetLeslToggle(void);
void OrganPro_SetDrawbar(uint8_t idx, uint8_t value);

void OrganPro_WheelSound(int type);

void OrganPro_UpdateClick(uint8_t mode);


#endif /* SRC_ML_ORGAN_PRO_H_ */

