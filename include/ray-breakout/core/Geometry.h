#ifndef RBREAKOUT_GEOMETRY_H
#define RBREAKOUT_GEOMETRY_H

namespace RBreakout::Core {

template <typename T, int D>
struct Point {
  T pos[D];
};

using Point2Df = Point<float, 2>;

template<>
struct Point<float, 2> {
  union {
    float pos[2];
    struct {
      float x, y;
    };
  };
};

} // RBreakout::Core

#endif //RBREAKOUT_GEOMETRY_H
