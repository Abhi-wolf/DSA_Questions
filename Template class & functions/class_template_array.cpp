#include <iostream>
using namespace std;

/*
    Class Templates like function templates, class templates are useful when a class defines something
    that is independent of the data type.

#  we can pass more than one data type as arguments to templates.
eg:- template <class T, class U> class A
    {
        T x;
        U y;
        public:
            A() { cout<<"constructor called\n";}
    }

    int main()
    {
        A <char,char>a;
        A <int,double>b;
    }

#   we can specify default arguments to templates.
eg:- template <class T, class U = char> class A {
public:
    T x;
    U y;
    A() { cout << "Constructor Called" << endl; }
};

int main()
{
    A<char> a; // This will call A<char, char>
    return 0;
}


*/

template <typename T>
class Array
{
private:
    T *ptr;
    int size;

public:
    Array(T arr[], int s);
    void print();
};

template <typename T>
Array<T>::Array(T arr[], int s)
{
    ptr = new T[s];
    size = s;
    for (int i = 0; i < size; i++)
        ptr[i] = arr[i];
}

template <typename T>
void Array<T>::print()
{
    for (int i = 0; i < size; i++)
        cout << *(ptr + i) << "  ";
    cout << endl;
}

int main()
{
    int arr1[5] = {1, 2, 3, 4, 5};
    Array<int> obj1(arr1, 5);
    obj1.print();

    double arr2[5] = {12.0, 13.0, 14.0, 15.0, 16.0};
    Array<double> obj2(arr2, 5);
    obj2.print();

    string arr3[5] = {"ranchi", "godda", "patna", "hisar", "kolkata"};
    Array<string> obj3(arr3, 5);
    obj3.print();

    return 0;
}