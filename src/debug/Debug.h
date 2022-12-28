#pragma once

#ifndef OSK_DEBUG_h
#define OSK_DEBUG_h

#include <Arduino.h>
#include <WiFi.h>
#include "ESPTelnet.h"


#if OSK_DEBUG_ON
  #if OSK_DEBUG_USE_SERIAL
    #define OSK_DEBUG_SER(format, ...)      DEBUG_SERIAL.print(DEBUG_PREFIX); DEBUG_SERIAL.printf(#format, #__VA_ARGS__); DEBUG_SERIAL.println("");
    #define OSK_DEBUG_S_SER(str)            DEBUG_SERIAL.print(DEBUG_PREFIX); DEBUG_SERIAL.println(str);
    #define OSK_DEBUG_S2_SER(str, str2)     DEBUG_SERIAL.print(DEBUG_PREFIX); DEBUG_SERIAL.print(str); DEBUG_SERIAL.println(str2);
  #else
    #define OSK_DEBUG_SER(format, ...)
    #define OSK_DEBUG_S_SER(str)
    #define OSK_DEBUG_S2_SER(str, str2)
  #endif

  #if OSK_DEBUG_USE_TELNET
    #define OSK_DEBUG_TEL(format, ...)      DEBUG_TELNET.print(DEBUG_PREFIX); DEBUG_TELNET.printf(#format, #__VA_ARGS__); DEBUG_TELNET.println("");
    #define OSK_DEBUG_S_TEL(str)            DEBUG_TELNET.print(DEBUG_PREFIX); DEBUG_TELNET.println(str);
    #define OSK_DEBUG_S2_TEL(str, str2)     DEBUG_TELNET.print(DEBUG_PREFIX); DEBUG_TELNET.print(str); DEBUG_TELNET.println(str2);
  #else
    #define OSK_DEBUG_TEL(format, ...)
    #define OSK_DEBUG_S_TEL(str)
    #define OSK_DEBUG_S2_TEL(str, str2)
  #endif

  #define DBG(format, ...)                  OSK_DEBUG_SER(format, __VA_ARGS__); OSK_DEBUG_TEL(format, __VA_ARGS__);
  #define DBG_S(str)                        OSK_DEBUG_S_SER(str); OSK_DEBUG_S_TEL(str);
  #define DBG_S2(str, str2)                 OSK_DEBUG_S2_SER(str, str2); OSK_DEBUG_S2_TEL(str, str2);

#else
  #define DBG(format, ...)
  #define DBG_S(str)
  #define DBG_S2(str, str2)
#endif

#if OSK_DEBUG_ON
#if OSK_DEBUG_USE_TELNET

extern ESPTelnet telnet;

#endif
#endif

#endif