#include <iostream>
using namespace std;

class maxHeap
{
    int *array;
    int heap_size;
    int capacity;

public:
    maxHeap(int cap)
    {
        this->capacity = cap;
        this->array = new int[this->capacity];
        this->heap_size = 0;
    }

    void Insert(int key);
    void Display();
    void Heapify(int ind);
    int LeftChildren(int ind);
    int RightChildren(int ind);
};

// INSERT KEY
void maxHeap::Insert(int key)
{
    if (heap_size == capacity)
    {
        cout << "Overflow \n";
        return;
    }

    heap_size++;
    int i = heap_size - 1;
    while (i > 0 && key > array[(i - 1) / 2])
    {
        array[i] = array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    array[i] = key;
}

// DISPLAY
void maxHeap::Display()
{
    if (heap_size == 0)
    {
        cout << "Empty\n";
        return;
    }
    for (int i = 0; i < heap_size; i++)
        cout << array[i] << ", ";

    cout << endl;
}

// HEAPIFY (used to heapify tree below the ind node)
void maxHeap::Heapify(int ind)
{
    int left = LeftChildren(ind);
    int right = RightChildren(ind);

    int maxEle = ind, temp;
    if (left != -1 && array[left] > array[maxEle])
    {
        maxEle = left;
    }

    if (right != -1 && array[right] > array[maxEle])
    {
        maxEle = right;
    }

    if (maxEle != ind)
    {
        swap(array[maxEle], array[ind]);
        Heapify(maxEle);
    }
}

// LEFT CHILDREN
int maxHeap::LeftChildren(int ind)
{
    int left = 2 * ind + 1;
    if (left < heap_size)
        return array[left];
    return -1;
}

// Right CHILDREN
int maxHeap::RightChildren(int ind)
{
    int right = 2 * ind + 2;
    if (right < heap_size)
        return array[right];
    return -1;
}

int main()
{
    maxHeap obj(10);

    obj.Insert(10);
    obj.Insert(20);
    obj.Insert(30);
    obj.Insert(40);
    obj.Insert(50);
    obj.Insert(60);

    obj.Display();
    return 0;
}