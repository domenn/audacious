#ifndef AUD__UTILITIES__TIME_HPP
#define AUD__UTILITIES__TIME_HPP

#include <chrono>
#include <iomanip>
#include <sstream>
#include <string>

#if defined(__unix__)
#define FUNC_LOCALTIME(time, structure) localtime_r(time, structure)
#else
#define FUNC_LOCALTIME(time, structure) localtime_s(structure, time)
#endif

namespace aud {
namespace dt {
inline std::string currentISO8601TimeUTC() {
  auto now = std::chrono::system_clock::now();
  auto itt = std::chrono::system_clock::to_time_t(now);
  std::ostringstream ss;
  std::tm stdtm{};
  FUNC_LOCALTIME(&itt, &stdtm);
  ss << std::put_time(&stdtm, "%FT%TZ");
  return ss.str();
}

inline std::string current_time(const char *format) {
  auto now = std::chrono::system_clock::now();
  auto itt = std::chrono::system_clock::to_time_t(now);
  std::ostringstream ss;
  std::tm stdtm{};
  FUNC_LOCALTIME(&itt, &stdtm);
  ss << std::put_time(&stdtm, format);
  return ss.str();
}

inline std::string current_time_with_ms(const char *format)  {
  auto now = std::chrono::system_clock::now();
  auto itt = std::chrono::system_clock::to_time_t(now);
  std::ostringstream ss;
  std::tm stdtm{};
  FUNC_LOCALTIME(&itt, &stdtm);
  ss << std::put_time(&stdtm, format);
  auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(
      now.time_since_epoch()) %
      1000;
  ss << '.' << std::setfill('0') << std::setw(3) << ms.count();
  return ss.str();
}

inline std::string current_time_h_m_s_ms() {
  auto now = std::chrono::system_clock::now();
  auto itt = std::chrono::system_clock::to_time_t(now);
  std::ostringstream ss;
  std::tm stdtm{};
  FUNC_LOCALTIME(&itt, &stdtm);
  ss << std::put_time(&stdtm, "%H:%M:%S");
  auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(
      now.time_since_epoch()) %
      1000;
  ss << '.' << std::setfill('0') << std::setw(3) << ms.count();
  return ss.str();
}
}
}

#endif
