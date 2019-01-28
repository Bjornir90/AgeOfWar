#include "Color.hpp"


Color::Color(int color) : color(color), text(NULL), resetAfter(false) {}

Color::Color(int color, char const*const text, bool resetAfter) : color(color),
  text(text), resetAfter(resetAfter) {}

char const * const Color::reset =
#if COLOR_ENABLED!=0
  "\033[0m";
#else
  "";
#endif

std::ostream& operator << (std::ostream& strm, const Color& c) {
  #if COLOR_ENABLED!=0
    strm << "\033[" << c.color << 'm';
  #endif

  if(c.text) strm << c.text;

  #if COLOR_ENABLED!=0
    if(c.resetAfter) strm << Color::reset;
  #endif

  return strm;
}
