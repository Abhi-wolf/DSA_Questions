#include <iostream>
#define SIZE 10
#define PRIME 7

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

int PrimeHash(int key)
{
    return PRIME - (key % PRIME);
}

int Double_Hash(int H[], int key)
{
    int idx = Hash(key);
    int i = 0;
    while (H[(idx + i * PrimeHash(idx)) % SIZE] != 0)
    {
        i++;
    }

    return (idx + i * PrimeHash(idx)) % SIZE;
}

void Insert(int H[], int key)
{
    int index = Hash(key);

    if (H[index] != 0)
    {
        index = Double_Hash(H, index);
    }

    H[index] = key;
}

int Search(int H[], int key)
{
    int ide = Hash(key);
    int i = 0;

    while (H[(ide + i * PrimeHash(ide)) % SIZE] != key)
    {
        i++;
        if (H[(ide + i * PrimeHash(ide)) % SIZE] == 0)
            return -1;
    }

    return (ide + i * PrimeHash(ide)) % SIZE;
}

int main()
{
    int A[] = {5, 25, 15, 35, 95};
    int n = sizeof(A) / sizeof(A[0]);

    Print(A, n, "A");

    int HT[10] = {0};
    for (int i = 0; i < n; i++)
        Insert(HT, A[i]);

    Print(HT, 10, "HT");

    int index = Search(HT, 5);
    cout << "key found at: " << index << endl;

    index = Search(HT, 26);
    cout << "key found at: " << index << endl;
    return 0;
}
