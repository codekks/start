#include <iostream>
#include <cmath>
#include <fstream>
#include <ctime>
#include <string>
using std::string

#ifndef UTILS_H
#define UTILS_H

namespace Excel {
  class Vector{
   string* data;
   int length;
   int capacity;
  
  public:
  Vector(int n=1);
  void back_push(string s);
  string operator[](int i);
  int size();
  void remove(int x);
  ~Vector();
  };
  
  class Stack{
    struct Node{
      Node* prev;
      string s;
      Node(Node* prev,string s):prev(prev),s(s){}
    };
    Node* current;
    Node start;
   public:
   Stack();
   void push();
   string pop();
   string peek();
   bool empty();
  };
}

#include <utils.h>
namespace Excel{
 Vector::Vector(int n):data(new string[n]), capacity(n), length(0){}
 void Vector::back_push(string s){
   if(capacity<=length){
   string* temp=new string[capacity*2];
   for(int i=0;i<length;i++){
   data[i]=temp[i];
   }
   temp[length]=s;
   delete[] data;
   data=temp;
   capacity*=2;
   length++;
  } 
   else {return 0;}
 }
 string Vector::operator[](int i){ return data[i];}
 int Vector::size(){return length;}
 void Vector::remove(int x){
   for(int i=x+1;i<length;i++){
     data[i-1]=data[i];
   }
   length--;
 }
 Vector::~Vector(){
   if(data){delete[] data;}
 }
 Stack::Stack(): start(NULL,""){current= &start;}
 void Stack::push(string s){Node* n=new Node(current,s);current=n;}
 string Stack::pop(){
   string s=current->s;
   Node* prev=current;
   current=current->prev;
   delete prev;
   return s;
 }
 string Stack::peek(){return current->s;}
 bool Stack::empty(){if(current==&start)return true; else false;}
 Stack::~Stack(){
   while(current!=&start){
     Node* prev=current;
     current=current->prev;
     delete prev;
   }
 }

}