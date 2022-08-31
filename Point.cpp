#include <cmath>

class Point {
  public:
    float x;
    float y;

    Point(float x, float y) {
      x = x;
      y = y;
    }
    
    float distanceTo(Point *point) {
      return pow(
        pow(x - point->x, 2) + pow(y - point->y, 2), 0.5
        );
    }
};
