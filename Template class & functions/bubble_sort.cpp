#include <iostream>
using namespace std;

template <typename T>
void bubbleSort(T a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                T temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

template <typename T>
void printArray(T a[], int n)
{
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << "  ";
    }
    cout << endl;
}

int main()
{
    // int arr[5]={2,8,3,6,1};
    char arr[5] = {'i', 'a', 'u', 'o', 'e'};
    printArray(arr, 5);
    bubbleSort(arr, 5);
    printArray(arr, 5);

    return 0;
}