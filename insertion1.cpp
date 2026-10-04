#include <iostream>
using namespace std;

int main()
{
    int arr[100], n;

    cout<<"Enter number of elements: ";
    cin>>n;

    cout<<"Enter elements:\n";
    for(int i=0;i<n;i++)
        cin>>arr[i];

    for(int i=1;i<n-1;i++)
    {
        int temp=arr[i];
        int j=i-1;

        while(j>=0 && arr[j]>temp)
        {
            arr[j+1]=arr[j];
            j--;
        }

        arr[j+1]=temp;
    }

    cout<<"Sorted Array:\n";

    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";

    return 0;
}