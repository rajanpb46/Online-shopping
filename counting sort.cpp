#include<iostream>
using namespace std;
int main()
{
    int a[5]={4,2,2,8,3};
    int count[10]={0};
    for(int i=0;i<5;i++)
    {
        count[a[i]]++;
    }
     
    cout<<"sorted array:";
    
    for(int i=0;i<10;i++)
    {
        while(count[i]>0)
        {
            cout<<i<<" ";
            count[i]--;
        }
    }
    return 0;
}