
#include <iostream>
#include "chains.h"
using namespace std;

//  gives index of array
int Hash(int key)
{
    return key % 10;
}

void Insert(struct Node *H[], int key)
{
    // first find the index of the array on which the key is to be inserted
    int index = Hash(key);

    //  then perform sortedinsert on the linked list  that the index of the array is pointing on
    SorrtedInsert(&H[index], key);
}

int main()
{
    struct Node *HT[10];
    struct Node *temp;
    int i;

    for (int i = 0; i < 10; i++)
        HT[i] = NULL;

    Insert(HT, 12);
    Insert(HT, 22);
    Insert(HT, 42);

    // frist argument gives the index of the array ,index contains pointer to the linked
    //  list on whcih searching is to be performed
    temp = Search(HT[Hash(22)], 22);

    if (temp)
        cout << temp->data << endl;
    else
        cout << "Not found\n";
    return 0;
}