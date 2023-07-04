#include <iostream>
using namespace std;

/*
    Given a string A and a dictionary of n words B, find out if A can be segmented into a space-separated
        sequence of dictionary words.

Example 1:
Input:
    n = 12
    B = { "i", "like", "sam", "sung", "samsung","mobile","ice","cream", "icecream", "man","go", "mango" },
    A = "ilike"
Output: 1
Explanation: The string can be segmented as "i like".
*/

class Node
{
public:
    char data;
    Node *children[26];
    bool isTerminal;

    Node(char ch)
    {
        data = ch;
        for (int i = 0; i < 26; i++)
            children[i] = NULL;
        isTerminal = false;
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

            p = p->children[ind];
        }
        p->isTerminal = true;
    }

    bool search(string word)
    {
        if (word.length() == 0)
            return true;

        Node *p = root;
        for (int i = 0; i < word.length(); i++)
        {
            int ind = word[i] - 'a';
            if (p->children[ind] == NULL)
                return false;
            p = p->children[ind];
        }
        return p->isTerminal;
    }

    bool solve(string str2)
    {
        if (str2.length() == 0)
            return true;

        Node *ptr = root;
        for (int j = 1; j <= str2.size(); j++)
        {
            string fir = str2.substr(0, j);
            string sec = str2.substr(j);

            bool fir_sea = search(fir);
            bool sec_sea = search(sec);

            // cout << fir << " first " << fir_sea << endl;
            // cout << sec << " second " << sec_sea << endl;

            if (fir_sea && sec_sea)
            {
                // cout << "true";
                return true;
            }
            else if (fir_sea)
            {
                if (solve(sec))
                    return true;
            }
        }
        return false;
    }
};

int main()
{
    string str1[] = {"i", "like", "sam", "sung", "samsung",
                     "mobile", "ice", "cream", "icecream", "man",
                     "go", "mango"};
    string str2 = "like";

    Trie ptr;
    for (auto x : str1)
        ptr.insert(x);

    // bool ans = ;
    cout << "answer = " << ptr.solve(str2) << endl;
    return 0;
}
