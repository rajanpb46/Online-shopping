#include<iostream>

using namespace std;

class Box{
    private:
        static int length;
        static int breadth;
        static int height;
    
    public:
       static void print()
       {
        cout<<"The value of the length is: "<<length<<endl;
        cout<<"The value of the breadth is: "<<breadth<<endl;
        cout<<"The value of the height is: "<<height<<endl;
       }
};

 int Box::length = 10;
 int Box::breadth = 5;
 int Box::height = 8;

 int main(){
    Box b;

    cout<<"Static member function called through object name: "<<endl;
    b.print();

    cout<<"Static member function called through class name: "<<endl;
    Box::print();
    return 0;
 }