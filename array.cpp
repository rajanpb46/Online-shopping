#include<iostream>
using namespace std;

int main(){
    int arr[100],n;

    cout<<"Enter the no. of element:";
    cin>>n;

    cout<<"Enter element:";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    cout<<"Array is: ";
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}