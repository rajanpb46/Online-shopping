#include <iostream>
using namespace std;

class Test
{
public:
    void display() const
    {
        cout << "This is a const member function." << endl;
    }
};

int main()
{
    const Test obj;

    obj.display();

    return 0;
}