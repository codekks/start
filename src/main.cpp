#include <iostream>
#include <cmath>
#include <fstream>
#include <ctime>
#include <string>

class Table{
  Cell*** data_base;
  int cell_x;
  int cell_y;
  int num_cellx;
  int num_celly;
 public:
  Table(int cell_x, int cell_y):cell_x(cell_x),cell_y(cell_y){
    num cellx, num_celly=0;
    int **data_base=new int*[cell_x]
    for(int i=0;i<cell_x;i++){
      data_base[i]=new int[cell_y];
    }
  }
  void add_cell(Cell*cell){
    data_base[num_cellx][num_celly]=cell;
    num_celly++;
    if(num_celly>cell_y){
      num_celly=0;
      num_cellx++;
    }
  }
  virtual std::string print_table(int x,int y){
    data_base[x][y]->show_cell();
  }
  
  ~Table(){
    for(int i=0;i<cell_alloc/10;i++){
      delete[] data_base[i];}
    delete [] data_base;
  }
    
};
ostream& operator<<(ostream&o, Table& t){
  o<<t.print_table();
  return o;
}
class Cell{
  Table *table;
  std::string data;
  int x,y;
 public:
 Cell(const std::string &data) : data(data) {};
 void show_cell(){
   return std::string data;
 }
};

class TextTable : public Table {
  std::ostream Text("test.txt");
  public:
  TextTable(std::ostream Text("test.txt"),int cell_x, int cell_y):Text(Text),Table(cell_x, cell_y);
  void print_table(int x, int y){
    if(Text.is_open()){
    Text << print_table(x,y);
    }
  }
};

"
class CSVTable : public Table {
  std::ostream CSV("test.csv");
};

class HTMLTable : public Table {
  std::ostream HTML("test.html");
};
"