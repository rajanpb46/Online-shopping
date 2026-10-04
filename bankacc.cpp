#include<iostream>

using namespace std;

class Demo{
private:
     int privateData;

    protected:
        int protectedData;
    
public:
    int publicData;

    void setData(int a ,int b, int c){
        privateData = a;
        protectedData = b;
        publicData = c;

    }

   void showData(){
       cout<<"Private Data: "<<privateData<<endl;
       cout<<"Protected Data: "<<protectedData<<endl;
       cout<<"Public Data: "<<publicData<<endl;

    }



};

int main(){
    Demo obj;
    obj.setData(10,20,30);
    obj.showData();

    return 0;
}