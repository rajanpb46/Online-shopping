#include<iostream>
#include<fstream>

using namespace std;

int main(){
    ifstream fin("notes.txt")
    if(!fin){
    cout<<"File not found!";
    return 1;
}

  string line;
  while(getline(fin,line)){
    cout<<line<<endl;
  }
  fin.close();
  return 0;
}