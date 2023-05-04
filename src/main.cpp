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
  class Cell{
    protected: 
    int x,y;
    Table* table;
    string data;
    public:
    virtual string stringify();
    virtual int to_numeric();

    Cell(int x, int y, string data, Table* table);
  };
  class Table{
    protected: 
    Cell*** data_base;
    int line_x, line_y;
    public:
    Table(line_x, line_y);
    ~Table();

    void add_cell(Cell* c, int x_, int y_);
    int to_numeric(const string& s);
    int to_numeric(int x_, int y_);
    string stringify(const string& s);
    string stringify(int row, int col);
    virtual string print_table();
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
 Cell::cell(string data, int x,int y, Table* table):data(data),x(x),y(y), table(table){}
 string Cell::stringify(){return data;}
 int Cell::to_numeric() { return 0; }
 Table::table(int line_x, int line_y):line_x(line_x),line_y(line_y){
   data_base= new Cell**[line_x];
   for(int i=0;i<line_x;i++){
     data_base[i]=new Cell*[line_y];
     for(int j;j<line_y;j++)
       data[i][j]=NULL;
   }
 }
 Table::~Table(){
   for(int i;i<line_x;i++){
     for(int j;j<line_y;j++)
       if(data_base[i][j]){delete data_base[i][j];}
     delete data_base[i];
   }
   delete data_base[];
 }
 int Table::add_cell(Cell* c, int i, int j){
   if(i<line_x&&j<line_y){
     if(data_base[i][j]) delete data_base[i][j];
     data_base[i][j]=c;
   }
 }
 
 int Table::to_numeric(const string& s){
   int i=s[0]-'a';
   int j=atoi(s.c_str+1)-1;
   if(i<line_x&&j<line_y){
    if(data_base[i][j]) delete data_base[i][j];
    data_base[i][j]->to_numeric;
   }
 }
 int
}
s