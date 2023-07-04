/*
            Prefix Suffix String
Given two Lists of strings s1 and s2, you have to count the number of strings in s2 which is either a suffix or prefix of at least one string of s1.

Example:
Input:
    s1 = ["cat", "catanddog", "lion"]
    s2 = ["cat", "dog", "rat"]
Output:
    2
Explanation:
    String "cat" of s2 is prefix of "catanddog" & string "dog" of s2 is suffix of "catanddog"
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    Node *children[26];
    bool isTerminal;

    Node()
    {
        for (int i = 0; i < 26; i++)
            children[i] = NULL;

        isTerminal = false;
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
        for (int i = 0; i < word.size(); i++)
        {
            int ind = word[i] - 'a';
            if (p->children[ind] == NULL)
                p->children[ind] = new Node();

            p = p->children[ind];
        }
        p->isTerminal = true;
    }

    bool search(string word)
    {
        Node *p = root;
        for (int i = 0; i < word.length(); i++)
        {
            int ind = word[i] - 'a';
            if (p->children[ind] == NULL)
                return false;

            p = p->children[ind];
        }
        return true;
    }
};

int main()
{
    string str1[] = {"jrjiml", "tchetn", "ucrhye", "ynayhy",
                     "cuhffd", "cvgpoiu", "znyadv"};
    string str2[] = {"jr", "ml", "cvgpoi", "gpoiu", "wnmkmluc",
                     "geheqe", "uglxagyl", "uyxdroj"};
    int ans = 0;

    Trie hell;
    //  insert the string as well as its reverse for suffix checking
    for (auto x : str1)
    {
        hell.insert(x);
        reverse(x.begin(), x.end());
        hell.insert(x);
    }

    // search for the prefix as well suffix
    //  search for string as well as its reverse
    for (auto b : str2)
    {
        string rev = b;
        reverse(rev.begin(), rev.end());

        if (hell.search(rev) || hell.search(b))
            ans++;
    }

    cout << "Answer = " << ans << endl;
}