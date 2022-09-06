#ifndef OSK_DEBUG_h
#define OSK_DEBUG_h

#include <Arduino.h>
#include <WiFi.h>
#include "ESPTelnet.h"

#if DEBUG_ON
  #if DEBUG_USE_SERIAL
    #define DEBUG_SER_MSG_SL(x)    DEBUG_SERIAL.print(x)
    #define DEBUG_SER_MSG(x)       DEBUG_SERIAL.println(x); DEBUG_SERIAL.print(DEBUG_PREFIX)
  #else
    #define DEBUG_SER_MSG_SL(x)
  #endif

  #if DEBUG_USE_TELNET
    #define DEBUG_TEL_MSG_SL(x)    DEBUG_TELNET.print(x)
    #define DEBUG_TEL_MSG(x)       DEBUG_TELNET.println(x); DEBUG_TELNET.print(DEBUG_PREFIX);
  #else
    #define DEBUG_TEL_MSG_SL(x)
  #endif

  #define DEBUG_MSG_NL(x)       DEBUG_SER_MSG(x); DEBUG_TEL_MSG(x)
  #define DEBUG_MSG(x)          DEBUG_SER_MSG_SL(x); DEBUG_TEL_MSG_SL(x)
#else
  #define DEBUG_MSG_NL(x)
#endif

#if DEBUG_ON
#if DEBUG_USE_TELNET

extern ESPTelnet telnet;

#endif
#endif

#endif