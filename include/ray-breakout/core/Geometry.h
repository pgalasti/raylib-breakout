#ifndef RBREAKOUT_GEOMETRY_H
#define RBREAKOUT_GEOMETRY_H

#include <cmath>

namespace RBreakout::Core {

template <typename T, int D>
struct Point {
  T pos[D];
};

using Point2Df = Point<float, 2>;

template<>
struct Point<float, 2> {
  
  Point() : x {0.0f}, y {0.0f} {}	
  Point(float x, float y) : x {x}, y {y} {}

  union {
    float pos[2];
    struct {
      float x, y;
    };
  };

  Point<float, 2> operator+(const Point<float, 2>& other) {
    return Point<float, 2>{this->x + other.x, this->y + other.y};
  }
  
  Point<float, 2> operator-(const Point<float, 2>& other) {
    return Point<float, 2>{this->x - other.x, this->y - other.y};
  }
  
  Point<float, 2>& operator+=(const Point<float, 2>& other) {
    x += other.x;
    y += other.y;
    return *this;
  }
  Point<float, 2>& operator-=(const Point<float, 2>& other) {
    x -= other.x;
    y -= other.y;
    return *this;
  }
};

using Vector2Df = Point2Df;

// This is a simple game. We don't need to do anything crazy with SIMD but
// it may be fun to implement in the future
namespace Math {

  inline float magnitude(const Vector2Df& v) {
    return std::sqrt(std::pow(v.x, 2) + std::pow(v.y, 2)); 
  }

} // RBReakout::Core::Math

} // RBreakout::Core

#endif //RBREAKOUT_GEOMETRY_H
