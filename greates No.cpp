#include<iostream>

using namespace std;

int main(){

    cout<<"Enter 1st number: ";
    int a;
    cin>>a;

    cout<<"Enter 2nd number: ";
    int b;
    cin>>b;

    cout<<"Enter 3rd number: ";
    int c;
    cin>>c;

    if(a>b && b>c){
        cout<<"A is greater";
    }

    else if(b>a && b>c){
        cout<<"B is greater";
    }
    else{
        cout<<"C is greater";
    }

    return 0;
}