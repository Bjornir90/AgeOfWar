#pragma once
#include <iostream>

#define COLOR_ENABLED 1

class Color {
public:
  enum {
    RED = 31,
    GREEN = 32,
    YELLOW = 33,
    BLUE = 34,
    MAGENTA = 35,
    CYAN = 36,
    BRIGHT_RED = 91,
    BRIGHT_GREEN = 92,
    BRIGHT_YELLOW = 93,
    BRIGHT_BLUE = 94,
    BRIGHT_MAGENTA = 95,
    BRIGHT_CYAN = 96
  };

  int const color;
  char const * const text;
  bool const resetAfter;

  Color(int color, char const*const text, bool resetAfter=true);
  Color(int color);

  static char const * const reset;

  friend std::ostream& operator << (std::ostream& strm, const Color& c);
};
