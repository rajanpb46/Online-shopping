#include <iostream>
using namespace std;

int arr[100], n;

void display()
{
    if(n==0)
    {
        cout<<"Array is empty.\n";
        return;
    }

    cout<<"Array Elements: ";
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

void insertEnd()
{
    int value;
    cout<<"Enter value: ";
    cin>>value;

    arr[n]=value;
    n++;

    cout<<"Element inserted at end.\n";
}

void insertPosition()
{
    int pos,value;

    cout<<"Enter position (1-"<<n+1<<"): ";
    cin>>pos;

    if(pos<1 || pos>n+1)
    {
        cout<<"Invalid Position\n";
        return;
    }

    cout<<"Enter value: ";
    cin>>value;

    for(int i=n;i>=pos;i--)
        arr[i]=arr[i-1];

    arr[pos-1]=value;
    n++;

    cout<<"Element inserted successfully.\n";
}

void deleteValue()
{
    int value,index=-1;

    cout<<"Enter value to delete: ";
    cin>>value;

    for(int i=0;i<n;i++)
    {
        if(arr[i]==value)
        {
            index=i;
            break;
        }
    }

    if(index==-1)
    {
        cout<<"Value not found.\n";
        return;
    }

    for(int i=index;i<n-1;i++)
        arr[i]=arr[i+1];

    n--;

    cout<<"Element deleted.\n";
}

void deletePosition()
{
    int pos;

    cout<<"Enter position: ";
    cin>>pos;

    if(pos<1 || pos>n)
    {
        cout<<"Invalid Position\n";
        return;
    }

    for(int i=pos-1;i<n-1;i++)
        arr[i]=arr[i+1];

    n--;

    cout<<"Element deleted.\n";
}

void search()
{
    int value;

    cout<<"Enter value to search: ";
    cin>>value;

    for(int i=0;i<n;i++)
    {
        if(arr[i]==value)
        {
            cout<<"Element found at position "<<i+1<<endl;
            return;
        }
    }

    cout<<"Element not found.\n";
}

int main()
{
    int choice;

    cout<<"Enter number of elements: ";
    cin>>n;

    cout<<"Enter elements:\n";
    for(int i=0;i<n;i++)
        cin>>arr[i];

    do
    {
        cout<<"\n===== MENU =====\n";
        cout<<"1. Insert at End\n";
        cout<<"2. Insert at Position\n";
        cout<<"3. Delete by Value\n";
        cout<<"4. Delete by Position\n";
        cout<<"5. Search Element\n";
        cout<<"6. Display Array\n";
        cout<<"7. Exit\n";

        cout<<"Enter choice: ";
        cin>>choice;

        switch(choice)
        {
            case 1: insertEnd(); break;
            case 2: insertPosition(); break;
            case 3: deleteValue(); break;
            case 4: deletePosition(); break;
            case 5: search(); break;
            case 6: display(); break;
            case 7: cout<<"Program Ended."; break;
            default: cout<<"Invalid Choice";
        }

    }while(choice!=7);

    return 0;
}