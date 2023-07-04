#include <iostream>
using namespace std;

/*                       Shortest Unique prefix for every word
    Given an array of words, find all shortest unique prefixes to represent each word in the given array. 
        Assume that no word is prefix of another.

Example 1:
Input: 
    N = 4
    arr[] = {"zebra", "dog", "duck", "dove"}
Output: z dog du dov
Explanation: 
    z => zebra 
    dog => dog 
    duck => du 
    dove => dov 

Example 2:
Input: 
    N = 3
    arr[] =  {"geeksgeeks", "geeksquiz","geeksforgeeks"};
Output: geeksg geeksq geeksf
Explanation: 
    geeksgeeks => geeksg 
    geeksquiz => geeksq 
    geeksforgeeks => geeksf
*/

class Node
{
public:
    char data;
    Node *children[26];
    bool isTerminal;
    int childCount;

    Node(char ch)
    {
        data = ch;
        for (int i = 0; i < 26; i++)
            children[i] = NULL;
        isTerminal = false;
        childCount = 0;
    }
};

class Trie
{
    Node *root;

public:
    Trie()
    {
        root = new Node('\0');
    }

    void insert(string word)
    {
        Node *p = root;
        for (int i = 0; i < word.length(); i++)
        {
            int ind = word[i] - 'a';
            if (p->children[ind] == NULL)
                p->children[ind] = new Node(word[i]);

            p->children[ind]->childCount++;
            p = p->children[ind];
        }
        p->isTerminal = true;
    }

    string search(string word)
    {
        string str = "";
        Node *p = root;
        for (int i = 0; i < word.length(); i++)
        {
            int ind = word[i] - 'a';
            if (p->children[ind]->childCount == 1)
            {
                str += word[i];
                return str;
            }

            else if (p->children[ind]->childCount > 1)
            {
                str += word[i];
            }
            p = p->children[ind];
        }
        return "";
    }
};

int main()
{
    string str[] = {"geeksgeeks", "geeksquiz","geeksforgeeks","zebra", "dog", "duck", "dove"};
    Trie ptr;

    for(auto x:str) {
        ptr.insert(x);
    }

    for(auto x:str) {
        string s=ptr.search(x);
        cout<<s<<" , ";
    }
    cout<<endl;
    return 0;
}