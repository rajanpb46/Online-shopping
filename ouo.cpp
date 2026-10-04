#include<iostream>
using namespace std;

class Number{
    int n;

    public:
    Number(int x=0) {n=x;}
    
    void operator++(){
        ++n;
    }

    void display(){
        cout<<"Number="<<n<<endl;

    }
};

 int main(){
    Number obj(10);
    obj.display();
    ++obj;
    obj.display();
    return 0;
    

 }

