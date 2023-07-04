#include <iostream>
using namespace std;

/*
    A binary heap is represented using a complete binary tree. A complete binary tree is a binary tree in which all
    the nodes at each level are completely filled except for the leaf nodes and the nodes are as far as left.

    A binary heap or simply a heap is a complete binary tree where the items or nodes are stored in a way such that
    the root node is greater than its two child nodes. This is also called max heap.

    The items in the binary heap can also be stored as min-heap wherein the root node is smaller than its two child nodes.
    We can represent a heap as a binary tree or an array.

    While representing a heap as an array, assuming the index starts at 0, the root element is stored at 0. In general,if a
    parent node is at the position I, then the left child node is at the position (2*I + 1) and the right node is at (2*I +2).


    Generally, Heaps can be of two types:
    Max-Heap: In a Max-Heap the key present at the root node must be greatest among the keys present at all of it’s children.
                The same property must be recursively true for all sub-trees in that Binary Tree.
    Min-Heap: In a Min-Heap the key present at the root node must be minimum among the keys present at all of it’s children.
                The same property must be recursively true for all sub-trees in that Binary Tree.
*/

void swap(int *x, int *y);

//          MIN HEAP
class MinHeap
{
    int *ptr;
    int capacity;
    int heap_size;

public:
    MinHeap(int cap)
    {
        heap_size = 0;
        capacity = cap;
        ptr = new int[cap];
    }

    void MinHeapify(int i);
    int parent(int i) { return (i - 1) / 2; }
    int left(int i) { return (2 * i + 1); }
    int right(int i) { return (2 * i + 2); }

    int extractMin();
    void decreaseKey(int i, int new_val);
    int getMin() { return ptr[0]; }
    void deleteKey(int i);
    void insertKey(int k);
    void display();
};
void MinHeap::insertKey(int k)
{
    if (heap_size == capacity)
    {
        cout << "\n Overflow : could not insert key \n";
        return;
    }

    heap_size++;
    int i = heap_size - 1;
    ptr[i] = k;

    while (i != 0 && ptr[parent(i)] > ptr[i])
    {
        swap(&ptr[i], &ptr[parent(i)]);
        i = parent(i);
    }
}

void MinHeap::decreaseKey(int i, int new_val)
{
    ptr[i] = new_val;
    while (i != 0 && ptr[parent(i) > ptr[i]])
    {
        swap(&ptr[i], &ptr[parent(i)]);
        i = parent(i);
    }
}

int MinHeap::extractMin()
{
    if (heap_size <= 0)
        return INT_MAX;
    if (heap_size == 1)
    {
        heap_size--;
        return ptr[0];
    }

    int root = ptr[0];
    ptr[0] = ptr[heap_size - 1];
    heap_size--;
    MinHeapify(0);

    return root;
}

void MinHeap::deleteKey(int i)
{
    decreaseKey(i, INT_MIN);
    extractMin();
}

void MinHeap::MinHeapify(int i)
{
    int l = left(i);
    int r = right(i);
    int smallest = i;

    if (l < heap_size && ptr[l] < ptr[i])
        smallest = i;
    if (r < heap_size && ptr[r] < ptr[smallest])
        smallest = r;
    if (smallest != i)
    {
        swap(&ptr[i], &ptr[smallest]);
        MinHeapify(smallest);
    }
}

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void MinHeap::display()
{
    int num = heap_size;
    for (int i = 0; i < num; i++)
    {
        cout << ptr[i] << "  ";
    }
    cout << endl;
}

int main()
{
    MinHeap obj(11);
    obj.insertKey(40);
    obj.insertKey(35);
    obj.insertKey(30);
    obj.insertKey(15);
    obj.insertKey(10);
    obj.insertKey(25);
    obj.insertKey(5);
    obj.display();
    obj.deleteKey(0);
    obj.display();
    return 0;
}