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
Complex(cosnt Complex& c){real = c.real, img = c.img;} ;

Complex operator+(const Complex& c);
Complex operator-(const Complex& c);
Complex operator*(const Complex& c);
Complex operator/(const Complex& c);
Complex& operator=(const Complex& c);
int pl(){std::cout<<real<<img<<std::endl;}
};
Complex::Complex(const char *str){
  double real=0.0;
  double img=0.0;
  int len=strlen(str);
  int i_num=0;
  int o_num=0;
  
  for (int i=0;i<len;i++){
    if(str[i]=="i") i_num=i break; 
    else i_num=-1;}
  for (int i=1;i<len;i++){
    if(str[i]=="+"||str[i]=="-") o_num=i; break; 
    else o_num=-1;}
  
  if(i_num==-1 && o_num==-1) real=atof(str);
  else if (o_num==-1) img=atof(str);
  else if(i_num>o_num){
    double *array_real = new double[len];
    for (int i=0;i<i_num;i++){
      array_real[i]=str[i];
    }
    real=atof(array_real);
    
    double *array_img = new double[len];  
    for (int i=i_num+1;i<len;i++){
      array_img[i-i_num-1]=str[i];
    }
    img=atof(array_img);
    delete [] array_img;
    delete [] array_real;
  }
   else if(i_num<o_num){
    double *array_img = new double[len];
    for (int i=1;i<o_num;i++){
      array_img[i]=str[i];
    }
    img=atof(array_img);

    double *array_real = new double[len]; 
    for (int i=o_num;i<len;i++){
      array_real[i-o_num]=str[i];
    } 
    real=atof(array_real);
    delete [] array_img;
    delete [] array_real;
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
  a = a + "-1.1 + i3.923";
  a.pl();
  a = a - "1.2 -i1.823";
  a.pl();
  
}


  

