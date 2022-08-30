#include <cmath>

class Point {
  public:
    float x;
    float y;
    
    float distanceTo(Point *point) {
      return pow(
        pow(x - point->x, 2) + pow(y - point->y, 2),
        0.5
        );
    }
};
