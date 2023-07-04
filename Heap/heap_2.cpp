#include <iostream>
#include <vector>
using namespace std;

void Insert(vector<int> &vec, int key)
{
    auto i = vec.size();
    vec.emplace_back(key);

    //  if i is even then call (i/2 -1)th index else call i/2 th index of the array
    while (i > 0 && key > vec[i % 2 == 0 ? (i / 2) - 1 : i / 2])
    {
        vec[i] = vec[i % 2 == 0 ? (i / 2) - 1 : i / 2];
        i = i % 2 == 0 ? (i / 2) - 1 : i / 2;
    }
    vec[i] = key;
}

void createHeap(vector<int> &vec, int A[], int n)
{
    for (int i = 0; i < n; i++)
        Insert(vec, A[i]);
}

//  we can only delete root of the tree(to maintain heap properties of the tree)
void Delete(vector<int> &vec, int n)
{
    int x, i, j;
    x = vec[n - 1];
    vec[0] = vec[n - 1];
    i = 0;
    j = 2 * i + 1;
    while (j < n - 1)
    {
        if (vec[j + 1] > vec[j])
            j = j + 1;
        if (vec[i] < vec[j])
        {
            int temp = vec[i];
            vec[i] = vec[j];
            vec[j] = temp;

            i = j;
            j = 2 * j;
        }
        else
            break;
    }
    vec[n] = x;
}

template <class T>
void print(T &vec, int n, char c)
{
    cout << c << " : [" << flush;
    for (int i = 0; i < n; i++)
    {
        cout << vec[i] << flush;
        if (i < n - 1)
            cout << ", " << flush;
    }
    cout << "]" << endl;
}

int main()
{
    int b[] = {10, 20, 30, 25, 5, 40, 35};
    print(b, sizeof(b) / sizeof(b[0]), 'b');

    vector<int> v;
    createHeap(v, b, sizeof(b) / sizeof(b[0]));
    print(v, v.size(), 'v');

    Delete(v, sizeof(b) / sizeof(b[0]));
    v.resize(v.size() - 1);
    print(v, v.size(), 'v');
    return 0;
}