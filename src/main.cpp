#include <iostream>
class Point {
  int x, y;
 public:
  Point(int pos_x, int pos_y){
      x=pos_x;
      y=pos_y;
}

class Geometry {
 private:
  Point* point_array[100];
  int num_points;
 public:
  Geometry() {
    num_points = 0;
  }
  void AddPoint(const Point &point) {
    point_array[num_points ++] = new Point(point.x, point.y);
  }

  int main(){
      Point point;
  }