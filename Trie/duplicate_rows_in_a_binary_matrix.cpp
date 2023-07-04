#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*  Given a boolean matrix of size RxC where each cell contains either 0 or 1, find the row
        numbers of row (0-based) which already exists or are repeated.
    Input:
        R = 4, C = 3
    matrix[][] = {{ 1, 0, 0},
              { 1, 0, 0},
              { 1, 0, 0},
              { 0, 0, 0}}
    Output:
        1 2
    Explanation:
        Row 1 and Row 2 are duplicates of Row 0.
*/

void repeatedRows(vector<vector<int>> vec, int m, int n)
{
    vector<int> ans;
    unordered_map<string, int> um;

    for (int i = 0; i < vec.size(); i++)
    {
        string s = "";
        for (int j = 0; j < vec[i].size(); j++)
        {
            s += (vec[i][j] + '0');
        }

        if (um.find(s) != um.end())
        {
            ans.push_back(i);
        }
        else
            um[s]++;
    }
    cout << "\nwithout trie = ";
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << "     ";
}

class Node
{
public:
    Node *children[2];
    bool isTermianl;

    Node()
    {
        for (int i = 0; i < 2; i++)
            children[i] = NULL;

        isTermianl = false;
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
            int ind = word[i] - '0';
            if (p->children[ind] == NULL)
                p->children[ind] = new Node();

            p = p->children[ind];
        }
        p->isTermianl = true;
    }

    bool search(string word)
    {
        Node *p = root;
        for (int i = 0; i < word.length(); i++)
        {
            int ind = word[i] - '0';
            if (p->children[ind] == NULL)
                return false;

            p = p->children[ind];
        }
        return p->isTermianl;
    }
};

int main()
{
    vector<vector<int>> vec;
    vec = {{1, 0, 0},
           {1, 0, 0},
           {1, 0, 0},
           {0, 0, 0}};

    repeatedRows(vec, 4, 3);

    // another method using trie
    Trie hello;
    vector<int> ans;

    for (int i = 0; i < vec.size(); i++)
    {
        string s = "";
        for (int j = 0; j < vec[i].size(); j++)
        {
            s += (vec[i][j] + '0');
        }

        if (hello.search(s))
            ans.push_back(i);

        else
            hello.insert(s);
    }
    cout << "\nusing trie = ";
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << "     ";
    return 0;
}
