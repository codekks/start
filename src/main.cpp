#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>

namespace Myclass{
  class Array;
  class Int;
}

class Array{
  private:
  friend Int;
  friend Iterator;

  const int dim;
  int* size;
  struct Address {int level; void* next_Address;};

 
  public:
  class Iterator{
    friend Int;

    int* location;
    Array* arr;
    public:
    Iterator(int* location_, Array* arr_):arr(arr_){
      location=new int*[arr_->dim]
      for(int i=0;i<arr->dim;i++){
        location[i]=location_[i];
      }
    Iterator(const Iterator& itr) : arr(itr.arr) {
      location = new int[arr->dim];
      for (int i = 0; i != arr->dim; i++) location[i] = itr.location[i];
    }
    ~Iterator() { delete[] location; }
    }



  };
  Array(int dim,int* size_):dim(dim){
    size = new int*[dim];
    for (int i=0;i<dim;i++) size=size_;
    top=new Address;
    top.level=0;
    make_string(Array)
  }
  Array(const Array& arr){
    size = new int*[arr.dim];
    for (int i=0;i<arr.dim;i++){size[i]=arr->size[i];}
    top=new Address;
    top.level=0;
    make_string(Array)
  }
  void make_string(const Address* a){
    if(!a) return;
    if (a->level==dim-1){
      next_Address=new int*[size[dim-1]];
      return;
    }
    a->next_Address=new Address*[size[a->level]]
    for(i=0;i<size[a->level];i++]){
      (static<Address*>(a->next_Address)+i)->level=a->level+1;
      make_string(static_cast<Address*>(a->next_Address)+i);
    }
  }
  void delete_string(Address* a){
    for(int i=0;a->level<dim-1&&i<size[a->level];i++){
      delete_string((static_cast<Address*>(a->next_Address)+i))
    }
    if(a->level==dim-1){delete[] static_cast<int *>(current->next);}
    else delete[] static_cast<Address*>(a->next);
  }
  /*
  void copy_string(Address* b,){
    if (b->level==dim-1){
      for(i=0;i<size[dim-1];i++) {
        static_cast<int*>(b->next)[i]=}
    for(i=0;i<size[b->level];i++){
      b->next_Address=new Address*[]
    }
  }*/
  ~Array(){
    delete_string(top);
    delete[] size;
  }
};

class Int{
  private:
    int level;
    void* data
    Array* arr;
 
  public:
    Int(int index, int level_=0, void* data_=NULL, Array* arr_=NULL)
    :level(level_),data(data_),arr(arr_){
      if(level_<0||index>arr->size[level_])
      return data_=NULL;
      if(level==arr->dim-1)
      data=static_cast<void*>((static_cast<int*>(static_cast<Array::Address*>(data)->next_Address)+index));
      else if(level<arr->dim)
      data=static_cast<void*>((static_cast<Array::Address*>(static_cast<Array::Address*>(data)->next_Address)+index));
      }
    Int(const Int& i){
      level=i.level;
      data=i->data;
      arr=i->arr;
    }
    operator int(){
      if(data) return *static_cast<int*>(data);
    }
    Int operator[](const int index){
      return Int(index, level+1, data, arr);
    }
    Int& operator=(const int& a){
      if(data) *static_cast<int*>(data)=a;
      return *this;
    }
};

  

int main(){
  int size[4]={1,2,3,4};
  Myclass::Array array(4, size);
}