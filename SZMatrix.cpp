#include<iostream>
#include "Point.cpp"
using namespace std;

class SZMatrix {
  
  private:
    static int THRESH;
    SZMatrix *matrix [2][2];
    int count;
    float minX;
    float maxX;
    float minY;
    float maxY;
  
  public:
    SZMatrix(float minX, float maxX, float minY, float maxY) {
      this->count = 0;
      this->minX = minX;
      this->maxX = maxX;
      this->minY = minY;
      this->maxY = maxY;
    }

    bool contains(Point *point) {
      return (
        this->minX >= point->x &&
        this->maxX <= point->x &&
        this->minY >= point->y &&
        this->maxY <= point->y
      );
    }

    void addPoint(Point *point) {
      if (!contains(point)) {
        cout << "Not Contained" << endl;
        return;
      } else if (count <= SZMatrix::THRESH) {

      }
    }
};

int SZMatrix::THRESH = 16;

int main() {
  cout << "hi" << endl;
  return 0;
}
