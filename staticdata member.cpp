#include<iostream>
using namespace std;

class A{
    public:
      static int x;
};
 
int A::x = 10;
int main(){
    A obj;
    cout<<"Accessing static data member:"<<obj.x<<endl;
    return 0;
}