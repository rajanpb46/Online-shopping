#include <iostream>
using namespace std;

int main()
{
    int arr[100], n, key;
    int low=0, high, mid;

    cout<<"Enter number of elements: ";
    cin>>n;

    cout<<"Enter elements in sorted order:\n";
    for(int i=0;i<n;i++)
        cin>>arr[i];

    cout<<"Enter element to search: ";
    cin>>key;

    high=n-1;

    while(low<=high)
    {
        mid=(low+high)/2;

        if(arr[mid]==key)
        {
            cout<<"Element found at position "<<mid+1;
            return 0;
        }
        else if(key<arr[mid])
            high=mid-1;
        else
            low=mid+1;
    }

    cout<<"Element not found.";

    return 0;
}