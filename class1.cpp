#include<iostream>

using namespace std;

class student{
public:
    string name;
    int age;
    int marks;

    void getdata(){
        cout<<"Enter name:";
        cin>>name;

        cout<<"Enter age:";
        cin>>age;

        cout<<"Enter marks:";
        cin>>marks; 
    }

    void displaydata(){
        cout<<"\nStudent Details:"<<endl;
        cout<<"Name: "<<name<<endl;
        cout<<"Age: "<<age<<endl;
        cout<<"Marks: "<<marks<<endl;
    }
};

int main(){
    student s1;
    s1.getdata();
    s1.displaydata();

    return 0;
 }

