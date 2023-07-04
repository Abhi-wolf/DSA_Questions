#include <iostream>
#define SIZE 10

using namespace std;

template <class T>
void Print(T &arr, int n, string s)
{
    cout << s << " : [";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i];
        if (i < n - 1)
            cout << " , ";
    }
    cout << "]" << endl;
}

int Hash(int key)
{
    return key % SIZE;
}

int Quadratic_probe(int H[], int key)
{
    int ide = Hash(key);
    int i = 0;
    while (H[(ide + (i * i)) % SIZE] != 0)
    {
        i++;
    }

    return (ide + (i * i)) % SIZE;
}

void Insert(int H[], int key)
{
    int index = Hash(key);

    if (H[index] != 0)
    {
        index = Quadratic_probe(H, index);
    }

    H[index] = key;
}

int Search(int H[], int key)
{
    int idx = Hash(key);
    int i = 0;

    while (H[(idx + (i * i)) % SIZE] != key)
    {
        i++;
        if (H[(idx + (i * i)) % SIZE] == 0)
            return -1;
    }

    return (idx + (i * i)) % SIZE;
}

int main()
{
    int A[] = {23, 43, 13, 27};
    int n = sizeof(A) / sizeof(A[0]);

    Print(A, n, "A");

    int HT[10] = {0};
    for (int i = 0; i < n; i++)
        Insert(HT, A[i]);

    Print(HT, 10, "HT");

    int index = Search(HT, 13);
    cout << "key found at: " << index << endl;

    index = Search(HT, 35);
    cout << "key found at: " << index << endl;
    return 0;
}
