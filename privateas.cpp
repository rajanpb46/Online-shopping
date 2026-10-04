#include<bits/stdc++.h>
using namespace std;

class Person{
    private:
      string personname;

    public:
        void setName(string name){
                personname = name;
            }
    
    void printname(){
        cout<<"Personname is: "<<personname<<endl;      
    }
};

int main(){
    Person obj1;
    obj1.setName("Rajan");
    obj1.printname();
    return 0;
}