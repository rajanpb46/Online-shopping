#include<iostream>
using namespace std;

class A
{
     public:
     int x;
     A()
     {
          x=20;

     }
};


class B:public A
{
     public:
     int y;
     B()
     {
          y=40;
     }
     void show(){
             cout<<"\n x ="<<x;
             cout<<"\n y ="<<y;
     }
};
int main(){
          B b;
          b.show();
          return 0;
}