#include <iostream>
#include <cmath>
#include <fstream>
#include <ctime>
#include <cstring>

class human{
private:
int age;
std::string name;
public:
 human(const std::string name, int age):name(name),age(age){}
 std::string get_info(){
  return "Name:"+name+"/Age:"+age;
}
 friend std::ofstream& operater<<(std::ofstream &o,human &h);
};
 
std::ofstream& operater<<(std::ofstream &o,human &h){
   o<<h.get_info();
   return o;
 }


int main(){
  humam h("고경수",22);
  std::ofstream out("test.txt");
  if(out.Is_open()){
    out<<h>>std::endl;
  }

 

  }
}