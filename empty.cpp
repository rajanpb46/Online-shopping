#include<iostream>

using namespace std;

class Empty{
};

 int main(){
    Empty obj;
    cout<<"Size of empty class object: "<<sizeof(obj)<<endl;
    return 0;
}