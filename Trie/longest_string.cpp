/*
    Given an array of strings arr[]. You have to find the longest string which is lexicographically smallest
        and also all of its prefix strings are already present in the array.

    Input: ab a aa abd abc abda abdd abde abdab
    Output: abdab
    Explanation: We can see that each string is fulfilling the condition. For each string, all of its prefix
        are present in the array.And "abdab" is the longest string among them. So the ouput is "abdab".
*/

// here the longest string will be that string whose every node along its path is the terminal node (it means that those are the substrings)

#include <iostream>
using namespace std;

class Node
{
public:
    Node *children[26];
    bool isEnd;

    Node()
    {
        for (int i = 0; i < 26; i++)
            children[i] = NULL;

        isEnd = false;
    }
};

class Trie
{
public:
    Node *root;

    Trie()
    {
        root = new Node();
    }

    void insert(string word)
    {
        Node *p = root;
        for (int i = 0; i < word.length(); i++)
        {
            int index = word[i] - 'a';
            if (p->children[index] == NULL)
                p->children[index] = new Node();

            p = p->children[index];
        }
        p->isEnd = true;
    }

    bool search(string word)
    {
        Node *p = root;
        for (int i = 0; i < word.length(); i++)
        {
            int index = word[i] - 'a';

            if (p->children[index] == NULL)
                return false;

            p = p->children[index];

            //  if the node is not a terminal node then it means that particular substring is not present
            if (!p->isEnd)
                return false;
        }
        return p->isEnd;
    }
};

int main()
{
    string str[] = {"ab", "a", "aa", "abd", "abc", "abda", "abdd", "abde", "abdab"};

    Trie hell;

    for (auto it : str)
        hell.insert(it);

    string ans = "";
    for (auto it : str)
    {
        if (hell.search(it))
        {
            if (it.size() > ans.size() || (it.size() == ans.size() && it < ans))
                ans = it;
        }
    }

    cout << "Longest string = " << ans << endl;
    return 0;
}