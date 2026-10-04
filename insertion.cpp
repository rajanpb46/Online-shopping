#include<iostream>
using namespace std;

int main(){

    int arr[100],n,pos,element;

    cout<<"Enter the number of elements in the array: ";
    cin>>n;

    cout<<"Enter the elements of the array: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    cout<<"Enter the position where you want to insert the element: ";
    cin>>pos;

    cout<<"Enter the element to be inserted: ";
    cin>>element;

    for(int i=n;i>=pos;i--){
        arr[i]=arr[i-1];
    }

    arr[pos-1]=element;
    cout<<"Array after insertion: ";
    for(int i=0;i<=n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}