#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

class Point {
  int x, y;
 public:
  Point(int pos_x, int pos_y){
      x=pos_x;
      y=pos_y;
  }
 int X(){return x;}
 int Y(){return y;}
};

class Geometry {
 private:
  Point* point_array[100];
  int num_points;
 
 public:
  Geometry() {
    num_points = 0;
  }
  void AddPoint(const Point &point) {
   point_array[num_points ++] = new Point(point.x,point.y);
  }
  void PrintDistance();
  void PrintNumMeets();
  };


  
  
  int main(){
      int i;
      std::cin>>i;
      Point point=Point(0,0);
      Geometry geometry; 
      for (int t=0;t<i;t++){
      srand(time(NULL));
      int rand_x=rand()%100;
      int rand_y=rand()%100;
      Point(rand_x,rand_y);
      Addpoint(point);

     }
  }
