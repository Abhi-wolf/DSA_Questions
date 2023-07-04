#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    Node *children[2];

    Node()
    {
        for (int i = 0; i < 2; i++)
            children[i] = NULL;
    }
};

class Trie
{
    Node *root;

public:
    Trie()
    {
        root = new Node();
    }

    void insert(int num)
    {
        Node *p = root;

        for (int i = 31; i >= 0; i--)
        {
            int bit = (num >> i) & 1;

            if (p->children[bit] == NULL)
                p->children[bit] = new Node();

            p = p->children[bit];
        }
    }

    int finMax(int num)
    {
        Node *p = root;
        int ans = 0;

        for (int i = 31; i >= 0; i--)
        {
            int bit = (num >> i) & 1;

            if (bit == 1)
            {
                if (p->children[0] != NULL)
                {
                    ans += (1 << i);
                    p = p->children[0];
                }
                else
                {
                    p = p->children[1];
                }
            }

            else
            {
                if (p->children[1] != NULL)
                {
                    ans += (1 << i);
                    p = p->children[1];
                }
                else
                {
                    p = p->children[0];
                }
            }
        }
        return ans;
    }
};


int main() {
    int arr[] ={9,5,3};
    Trie hello;

    for(int i=0;i<3;i++) {
        hello.insert(arr[i]);
    }

    int maxi=INT_MAX;
    for(int i=0;i<3;i++) {
        maxi = min(maxi,hello.finMax(arr[i]));
    }

    cout<<"maximum = "<<maxi<<endl;
    return 0;
}