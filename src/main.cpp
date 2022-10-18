#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>

class string {
  char *str;
  int len;

 public:
  string(char c,int n){
  len=n;
  str=new char [len+1];
  for (int i=0;i<len;i++){
   str[i]=c;
   }
   str[len+1]='\0';
  }
  string(const char *s){
    strcpy(str,s);
  }
  string(const string &s){
  len=s.len;
  str=new char[strlen(s.str)+1];
  strcpy(str,s.str);}
  ~string(){
    if (str) delete[] str;
  }

  void add_string(const string &s)   // str 뒤에 s 를 붙인다.
  {char *new_str=new char[strlen(str)+strlen(s.str)+1];
   for(int i=0;i<len;i++) new_str[i]=str[i];
   for(int j=len;j<len+strlen(s.str);j++) new_str[j]=s.str[j];
   new_str[len+strlen(s.str)+1]='\0';
   delete[] str;
   str=new char [strlen(new_str)+1];
   strcpy(str,new_str);
   }
  void copy_string(const string &s)  // str 에 s 를 복사한다.
  {delete [] str;
   str=new char[len+strlen(s.str)+1];
   strcpy(str,s.str);
  }
                       // 문자열 길이 리턴
};

int main(){
  string s();
}