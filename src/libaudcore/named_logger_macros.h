#ifndef LIBAUDCORE_LOGGER_MACROS_NAMED_H
#define LIBAUDCORE_LOGGER_MACROS_NAMED_H

#include <string>
#include <libaudcore/runtime.h>

#ifndef NO_HOTKEY_FLOW
#define L_HOTKEY_FLOW(tok) AUDWARN((std::string("hotkey_flow - ") + tok + "\n").c_str())
#else
#define L_HOTKEY_FLOW(...)
#endif

#ifndef NO_LOGGER_AUD_TESTING
#define L_AUD_TESTING(tok) AUDWARN((std::string("aud_testing - ") + tok + "\n").c_str())
#else
#define L_AUD_TESTING(...)
#endif

#endif