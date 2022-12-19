#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>



class Array{
  private:
  const int dim;
  int* size;
  struct Address {int level; void* next_Address;};

 
  public:
  Array(int dim,int* size_):dim(dim){
    size = new int*[dim];
    for (int i=0;i<dim;i++) size=size_;
    top=new Address;
    top->level=0;
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
    delete[] static_cast<Address*>(a->next);
  }
  void copy_string(Address* b,){
    if (b->level==dim-1){
      for(i=0;i<size[dim-1];i++) {
        static_cast<int*>(b->next)[i]=}
    for(i=0;i<size[b->level];i++){
      b->next_Address=new Address*[]
    }
  }
  ~Array(){
    delete_string(top);
    delete[] size;
  }
  
};


  

