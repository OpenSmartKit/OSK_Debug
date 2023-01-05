#pragma once

#ifndef OSK_DEBUG_h
#define OSK_DEBUG_h

#include <Arduino.h>
#include <WiFi.h>
#include "ESPTelnet.h"

/*
  Use DBG(string, arg1[, arg2, ...]) for formatted debug output like printf(string, arg1[, arg2, ...]) or single string output.
  Use DBG_VAR(arg) to debug output single variable string, number or char
*/

#if OSK_DEBUG_ON
  #if OSK_DEBUG_USE_SERIAL
    #define OSK_DEBUG_SER(format, ...)      DEBUG_SERIAL.print(DEBUG_PREFIX); DEBUG_SERIAL.printf(format __VA_OPT__(,) __VA_ARGS__); DEBUG_SERIAL.println("");
    #define OSK_DEBUG_VAR_SER(str)          DEBUG_SERIAL.print(DEBUG_PREFIX); DEBUG_SERIAL.println(str);
  #else
    #define OSK_DEBUG_SER(format, ...)
    #define OSK_DEBUG_VAR_SER(str)
  #endif

  #if OSK_DEBUG_USE_TELNET
    #define OSK_DEBUG_TEL(format, ...)      DEBUG_TELNET.print(DEBUG_PREFIX); DEBUG_TELNET.printf(format __VA_OPT__(,) __VA_ARGS__); DEBUG_TELNET.println("");
    #define OSK_DEBUG_VAR_TEL(str)          DEBUG_TELNET.print(DEBUG_PREFIX); DEBUG_TELNET.println(str);
  #else
    #define OSK_DEBUG_TEL(format, ...)
    #define OSK_DEBUG_VAR_TEL(str)
  #endif

  #define DBG(format, ...)                  OSK_DEBUG_SER(format __VA_OPT__(,) __VA_ARGS__); OSK_DEBUG_TEL(format __VA_OPT__(,) __VA_ARGS__);
  #define DBG_VAR(str)                      OSK_DEBUG_VAR_SER(str); OSK_DEBUG_VAR_TEL(str);

#else
  #define DBG(format, ...)
  #define DBG_VAR(str)
#endif

#if OSK_DEBUG_ON
#if OSK_DEBUG_USE_TELNET

extern ESPTelnet telnet;

#endif
#endif

#endif