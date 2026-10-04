#include <iostream>
using namespace std;

class Student
{
private:
    int rollNo;

public:
    Student(int r)
    {
        rollNo = r;
    }

    void display() const
    {
        cout << "Roll Number = " << rollNo << endl;
    }
};

int main()
{
    Student s(101);

    s.display();

    return 0;
}