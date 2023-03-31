#include <iostream>
#include <cmath>
#include <fstream>
#include <ctime>
#include <string>
using std::string

namespace Excel {
  class Vector{
   string* data;
   int length;
   int capacity;
  
  public:
  Vector(int n=1);
  void back_push(string s);
  string operator[](int i);
  string pop();
  string peek();
  bool empty();
  };
  
  class Stack{
    struct Node{
      Node* prev;
      string s;
      Node(string s):prev
    };
  };
}