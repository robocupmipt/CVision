#pragma once

struct Point {
  Point(float x = 0, float y = 0) : x(x), y(y) {}
  Point(const Point &other) : x(other.x), y(other.y) {}

  Point& operator +=(const Point &p) {
    x += p.x;
    y += p.y;
    return *this;
  }
  Point operator +(const Point& p) const {
    return Point(*this) += p;
  }

  Point& operator /=(float k) {
    x /= k;
    y /= k;
    return *this;
  }
  Point operator /(float k) {
    return Point(*this) /= k;
  }

  float x;
  float y;
};