#include <iostream>
#include <limits>
#include "Point.cpp"
using namespace std;

int THRESH = 16;

class SZMatrix {
  
  private:
    SZMatrix *matrices [2][2];
    int count;
    float minX;
    float maxX;
    float minY;
    float maxY;
    float meanX;
    float meanY;
    bool isSplitted;
    Point *points [16];

    int * findSubmatrix(Point *point) {
      static int toReturn[2];
      toReturn[0] = point->x >= meanX;
      toReturn[1] = point->y >= meanY;
      return toReturn;
    }

    SZMatrix getSubmatrix(Point *point) {
      int *submatrixCoords = findSubmatrix(point);
      SZMatrix matrix = *matrices[submatrixCoords[0]][submatrixCoords[1]];
      return matrix;
    }

    void splitMatrix() {
      if (count <= THRESH) return;

      SZMatrix m1(minX, meanX, minY, meanY);
      SZMatrix m2(meanX, maxX, minY, meanY);
      SZMatrix m3(minX, meanX, meanY, maxY);
      SZMatrix m4(meanX, maxX, meanY, maxY);

      matrices[0][0] = &m1;
      matrices[0][1] = &m2;
      matrices[1][0] = &m3;
      matrices[1][1] = &m4;

      isSplitted = true;
      
      for (int i = 0; i > count; i++) {
        Point *point = points[i];
        SZMatrix matrix = getSubmatrix(point);
        matrix.addPoint(point);
      }
    }

    bool contains(Point *point) {
      return (
        minX >= point->x &&
        maxX <= point->x &&
        minY >= point->y &&
        maxY <= point->y
      );
    }

  public:
    SZMatrix(float minX, float maxX, float minY, float maxY) {
      count = 0;
      minX = minX;
      maxX = maxX;
      minY = minY;
      maxY = maxY;
      meanX = (minX + maxX) / 2;
      meanY = (minY + maxY) / 2;
      isSplitted = false;
    }

    void addPoint(Point *point) {
      if (!contains(point)) {
        cout << "Not Contained" << endl;
        return;
      } else if (isSplitted) {
        SZMatrix submatrix = getSubmatrix(point);
        submatrix.addPoint(point);
      } else {
        points[count] = point;
        count++;
        splitMatrix();
      }
    }

    Point* getClosestPoint(Point *point) {
      if (count <= 0) {
        return NULL;
      } else if (isSplitted) {
        SZMatrix matrix = getSubmatrix(point);
        return matrix.getClosestPoint(point);
      } else {
        float closestDistance = std::numeric_limits<float>::max();
        Point *closestPoint;
        for (int i = 0; i < count; i++) {
          Point testPoint = *points[i];
          float distance = testPoint.distanceTo(point);
          if (distance < closestDistance) {
            closestDistance = distance;
            closestPoint = &testPoint;
          }
        }
        return closestPoint;
      }
    }
};

int main() {
  return 0;
}
