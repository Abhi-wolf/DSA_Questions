#include <iostream>
using namespace std;

//  C++ PROGRAM TO SHOW DIFFERENT DATA TYPES USING A CONSTRUCTOR AND TEMPLATE

template <class T>
class info
{
public:
    info(T a)
    {
        cout << "\n a = " << a << " size of data in types : " << sizeof(a);
    }
};

int main()
{
    //  passing character value by creating an object in the main() function.
    info<char> p('t');

    //  passing integer value by creating an object in the main() function.
    info<int> q(22);

    //  passing double value by creating an object in the main() function.
    info<double> r(2.25);
    return 0;
}