#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>

class string{
  private:
  int len;
  int memory;
  char *str;
  

  public:
  string(int len,char c);
  string(const char*s);
  string(const string&s);
   ~string(){if(str) delete[] str;}
  
  int pi=0;
  int length(); 
  int memory_capacity();
  void reserve(int size);

  string& assign(const char*s);
  string& assign(const string&s);
  
  string& insert(int num,const char*s);
  string& insert(int num,const string&s);
  
  string& earase(int num,int num_end);
  
  void PrintString(const char*s);
  void PrintString(const string&s);
  
  void Search(const string&s1);
  void KMP_Algorithm(const string&s,const string&s_search);

};

string::string(int t,char c){
  str=new char[t];
  for (int i=0;i<t;i++){
    str[i]=c;
  }
  len=t;
  memory=t;
}
string::string(const char*s){
  len=strlen(s);
  memory=strlen(s);
  str=new char[len];
  for (int i=0;i<len;i++){
    str[i]=s[i];
  }
}
string::string(const string&s){
  len=s.len;
  memory=strlen(s.str);
  str=new char[len];
  for (int i=0;i<len;i++){
    str[i]=s.str[i];
  }
}
int string::length(){
  return len;
}
int string::memory_capacity(){
  return memory;
}
void string::reserve(int size){
  if(size>memory){
    char* pre_str=str;
    delete[] str;
    str=new char[size];
    memory=size;
    for (int i=0;i<len;i++){
      str[i]=pre_str[i];
    }
    delete[] pre_str;
  }
}
string&string:: assign(const string&s){
  if(memory<s.len){
    delete[] str;
    str=new char[s.len];
    memory=s.len;
    }
  for(int i=0;i<s.len;i++) str[i]=s.str[i];
  len=s.len;
  return *this;
  }
string&string:: assign(const char*s){
  int s_len=strlen(s);
  if(memory<s_len){
    delete[] str;
    str=new char[s_len];
    memory=s_len;
    }
  for(int i=0;i<s_len;i++) str[i]=s[i];
  len=s_len;
  return *this;
  }
string& string::insert(int num,const string&s){
  if(num>len) return *this;
  if(s.len+len>memory){
    char* pre_str=str;
    delete[] str;
    str=new char[s.len+len];
    memory=s.len+len;
  for(int i=0;i<num;i++)
    str[i]=pre_str[i];
  for(int i=num;i<s.len+num;i++)
    str[i]=s.str[i-num];
  for(int i=num+s.len;i<len+s.len;i++)
    str[i]=pre_str[i-s.len];
  delete[] pre_str;
  len+=s.len;
  }
  else{
    for(int i=num+s.len;i<s.len+len;i++)
      str[i]=str[i-s.len];
    for(int i=num;i<len+s.len;i++)
      str[i]=s.str[i-num];
    len+=s.len;
  }
  
  return *this;
}
string& string::insert(int num,const char*s){
  string temp=string(s);
  return insert(num, temp);
}

void string::PrintString(const string& s){
  for(int i=0;i<len;i++)
  std::cout<<s.str[i];
  std::cout<<std::endl;
}
void string::PrintString(const char* s){
  string t=string(s);
  PrintString(t);
}
void string::Search(const string&s1){
  int t=0;
  char *pi_string=new char [s1.len];
  pi_string={0,};
  for(int a=2;a<=len;a++){
     for(int i=1;i<a;i++){
      for (int j=i;j<a;j++){ 
        if(s1.str[j-i]==s1.str[j]){t=1;}           
        else {t=0; break;}
      }
      if(t==1){pi=a-i; break;}
      std::cout<<pi<<std::endl;
     }
     pi_string[a-1]=pi;
  }
  for(int i=0;i<s1.len;i++){
    std::cout<<pi_string[i];
    } 
  std::cout<<std::endl;
}
void string::KMP_Algorithm(const string&s,const string&s_search){
int kmp=0;
if(s_search.pi==0||s_search.pi>s_search.len/2+1) std::cout<<"do a different thing!"<<std::endl;
else{
  for(int i=0;i<=s.len-s_search.len;i++){
    if(kmp==1){std::cout<<"there is a same word at "<<i<<std::endl;}
    for(int j=0;j<s_search.pi;j++){
      if(s.str[i+j]==s_search.str[j]){kmp=1;}
      else{kmp=0; break;}
    }
    if(kmp==1){ 
     for(int j=s_search.len-s_search.pi;j<s_search.len;j++){
       if(s.str[i+j]==s_search.str[j]){kmp=1;}
       else {kmp=0; i+=s_search.pi; break;}
     }
     if(kmp==1){
       for(int j=s_search.pi;j<s_search.len-s_search.pi;j++){
         if(s.str[i+j]==s_search.str[j]){kmp=1;}
         else{kmp=0; i+=s_search.len-s_search.pi; break;}
         }
       }
     else continue;
     }
  }
}

}

int main(){
string s=string("abcdcdabcdacaabcsabcdabc");
string s_s("abcdabc");
s_s.Search(s_s);


}