#include <iostream>
using namespace std;

/*
    A template is a simple yet very powerful tool in C++. The simple idea is to pass data type as a parameter
    so that we don’t need to write the same code for different data types. For example, a software company may
    need to sort() for different data types. Rather than writing and maintaining multiple codes, we can write one
    sort() and pass data type as a parameter.

    Templates are expanded at compiler time. This is like macros. The difference is, that the compiler does type
    checking before template expansion. The idea is simple, source code contains only function/class, but compiled
    code may contain multiple copies of the same function/class.


    What is the difference between function overloading and templates?

    Both function overloading and templates are examples of polymorphism features of OOP. Function overloading is used
    when multiple functions do quite similar (not identical) operations, templates are used when multiple functions do
    identical operations.

*/

template <typename T>
T maximum(T x, T y)
{
    return (x > y) ? x : y;
}

template <typename X>
X minimum(X a, X b)
{
    return (a < b) ? a : b;
}

int main()
{
    cout << "\nMaximum : " << maximum<int>(2, 8) << endl;
    cout << "Minimum : " << minimum<int>(2, 8) << endl;

    cout << "\nMaximum : " << maximum<double>(4.0, 5.0) << endl;
    cout << "Minimum : " << minimum<double>(2.0, 5.0) << endl;

    cout << "\nMaximum : " << maximum<char>('c', 'p') << endl;
    cout << "Minimum : " << minimum<char>('c', 'p') << endl;
    return 0;
}