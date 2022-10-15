#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

class Point {
 public: 
  int x, y;
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
   point_array[num_points++] = new Point(point.x,point.y);
  }
  void PrintDistance(int a, int b){
   int xy[2]={0,};
   xy[0]=point_array[a]->X()-point_array[b]->X();
   xy[1]=point_array[a]->Y()-point_array[b]->Y();
   double d=sqrt(xy[0]*xy[0]+xy[1]*xy[1]);
   std::cout<<"distance between point"<<a<<" and point"<<b<<":"<<std::endl;
   std::cout<<d<<std::endl; 
  }
  void PrintNumMeets();
  void PrintPoint(){
    std::cout<<"what point?"<<std::endl;
    int c;
    std::cin>>c;
    std::cout<<"x:"<<point_array[c]->X()<<" y:"<<point_array[c]->Y()<<std::endl;
  }
};
  
  
  int main(){
      Geometry geometry; 
     int j;
     
     while(1){
     std::cout<<"what do you want?"<<std::endl;
     std::cout<<"1. Add point"<<std::endl;
     std::cout<<"2. Show point"<<std::endl;
     std::cout<<"3. know distance between points"<<std::endl;
     std::cout<<"4. know how many points meet"<<std::endl;
    
     std::cin>>j;
     switch(j){
     case 1:{
       int i;
       std::cout<<"How many points:";
       std::cin>>i;
       srand(time(NULL));
       for (int t=0;t<i;t++){
       int rand_x=rand()%100;
       int rand_y=rand()%100;
       Point point(rand_x,rand_y);
       geometry.AddPoint(point);
       }
       std::cout<<"Added!"<<std::endl;
     break;
     }
    
     case 2:{
       geometry.PrintPoint();
       break;
     }
     
     
     case 3:{
       int t,p;
       std::cout<<"select two points:";
       std::cin>>t;
       std::cout<<"next:";
       std::cin>>p;
       geometry.PrintDistance(t,p);
       break;
     }
    }
    if (j==5){break;}
  }
}

