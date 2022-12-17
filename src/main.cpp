#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>

class Complex{
private:
   double real, img;


public:
Complex(double real, double img) : real(real), img(img) {}
Complex(const char *str);
Complex(const Complex& c){real = c.real, img = c.img;} ;

Complex operator+(const Complex& c) const;
Complex operator-(const Complex& c) const;
Complex operator*(const Complex& c) const;
Complex operator/(const Complex& c) const;
Complex& operator=(const Complex& c);
void pl(){std::cout << "( " << real << " , " << img << " ) " << std::endl;}
};
Complex::Complex(const char *str){
 
  int len=strlen(str);
  int i_num=-1;
  int o_num=-1;
  
  for (int i=0;i<len;i++){
    if(str[i]=='i') {i_num=i; break;}
    else i_num=-1;}
  for (int i=1;i<len;i++){
    if(str[i]=='+'||str[i]=='-') {o_num=i; break;} 
    else o_num=-1;}

  if(i_num==0){
    char str_n[len];
    for(int i=1;i<len;i++){
      str_n[i]=str[i-1];
    }
    img=atof(str_n);
  }
  else if(i_num==-1) {real = atof(str) ;}
  else if(i_num>0){
    char str_n1[len];
    char str_n2[len];
    for(int i=0;i<i_num-1;i++){
      str_n1[i]=str[i];
    }
    for(int i=i_num+1;i<len;i++){
      str_n2[i-i_num-1]=str[i];
    }
    real=atof(str_n1);
    
    img=atof(str_n2);
  
    if(str[i_num-1]=='-'){img=-img;}
  }

}
Complex Complex::operator+(const Complex& c) const {
  Complex temp(real + c.real, img + c.img);
  return temp;
}
Complex Complex::operator-(const Complex& c) const {
  Complex temp(real - c.real, img - c.img);
  return temp;
}
Complex Complex::operator*(const Complex& c) const {
  Complex temp(real * c.real - img * c.img, real * c.img + img * c.real);
  return temp;
}
Complex Complex::operator/(const Complex& c) const {
  Complex temp(
      (real * c.real + img * c.img) / (c.real * c.real + c.img * c.img),
      (img * c.real - real * c.img) / (c.real * c.real + c.img * c.img));
  return temp;
}   

Complex& Complex::operator=(const Complex& c) {
  real = c.real;
  img = c.img;
  return *this;
}
    
int main(){
  Complex a(0,0);
  Complex b = Complex("-1.1+i3.923");
  b.pl();
  a = a - "1.2-i1.823";
  a.pl();
}


  

