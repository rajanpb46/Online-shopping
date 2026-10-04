#include<iostream>

using namespace std;
int main(){
   

     class Car{
        public:
        string model;
        int speed;
        int year;
        string engine;
        int price;
    
     };

     Car car;
     car.model = "Toyota";
     car.speed = 120;
     car.year = 2023;
     car.engine = "V6";
     car.price = 500000;

     cout<<"Car Model: "<<car.model<<endl;
     cout<<"Car Speed: "<<car.speed<<endl;
     cout<<"Car Year: "<<car.year<<endl;
     cout<<"Car Engine: "<<car.engine<<endl;
     cout<<"Car Price: "<<car.price<<endl;

     return 0;
}