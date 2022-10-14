#include <iostream>
#include <cmath>

class Point {
  int x, y;
 public:
  Point(int pos_x, int pos_y){
      x=pos_x;
      y=pos_y;
  }
};

class Geometry {
 private:
  Point* point_array[100];
  int num_points;
 
 public:
  Geometry() {
    num_points = 0;
  }
  void AddPoint() {
     srand(time(NULL));
     int random_x=rand()%100;
     int random_y=rand()%100;
     point_array[num_points ++] = new Point(rando   m_x, random_y);
  }
  void PrintDistance();
  void PrintNumMeets();
};

void PrintDistance(int i,int j){
  int distance=0;
};
  
  
  int main(){
      int i,j;
      Geometry geometry; 
      for (int t=0;t<100;t++){
        geometry.AddPoint();
      }
  std::cin>>i>>j;
  std::cout<<*geometry.point_array[i]
  }