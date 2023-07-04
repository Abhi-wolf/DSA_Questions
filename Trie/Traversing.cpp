#include <iostream>
#include <vector>
#define MAX_SIZE 100
using namespace std;

vector<string>ans;

class trieNode
{
public:
    char data;
    trieNode *children[2];
    bool isTerminal;

    trieNode(char x)
    {
        this->data = x;
        for (int i = 0; i < 2; i++)
            children[i] = NULL;

        this->isTerminal = false;
    }
};

class Trie
{
public:
    trieNode *root;

    Trie()
    {
        root = new trieNode('\0');
    }

    void insertUtil(trieNode *root, string word)
    {
        if (word.length() == 0)
        {
            root->isTerminal = true;
            return;
        }

        int index = word[0] - '0';
        trieNode *child;

        if (root->children[index] != NULL)
            child = root->children[index];

        else
        {
            child = new trieNode(word[0]);
            root->children[index] = child;
        }

        insertUtil(child, word.substr(1));
    }

    void insert(string word)
    {
        insertUtil(root, word);
    }

    bool searchUtil(trieNode *root, string word)
    {
        if (word.length() == 0)
            return root->isTerminal;

        int index = word[0] - '0';
        trieNode *child;

        if (root->children[index] != NULL)
            child = root->children[index];

        else
        {
            return false;
        }

        return searchUtil(child, word.substr(1));
    }

    bool search(string word)
    {
        return searchUtil(root, word);
    }

    void print(char *str, int n)
    {
        string hell="";
        for (int i = 0; i < n; i++)
            hell+=str[i];
        
        ans.push_back(hell);
    }

    void Traverse(trieNode *root, char *word, int pos = 0)
    {
        if (root == NULL)
            return;

        if (root->isTerminal)
            print(word, pos);

        for (int i = 0; i < 2; i++)
        {
            if (root->children[i] != NULL)
            {
                word[pos] = i + '0';
                Traverse(root->children[i], word, pos + 1);
            }
        }
    }

    void traversingTrie()
    {
        char word[MAX_SIZE];
        Traverse(root, word);
    }
};

int main()
{
    Trie *temp = new Trie();
    int r = 3, c = 4;
    int arr[r][c] =
        {
            {1, 1, 0, 1},
            {1, 0, 0, 1},
            {1, 1, 0, 1}};

    for (int i = 0; i < r; i++)
    {
        string str = "";
        for (int j = 0; j < c; j++)
        {
            str += (arr[i][j] == 0) ? '0' : '1';
        }
        cout << str << "\n";
        temp->insert(str);
    }

    // vector<string> vec;

    // for (int i = 0; i < r; i++)
    // {
    //     string str = "";
    //     for (int j = 0; j < c; j++)
    //     {
    //         str += (arr[i][j] == 0) ? '0' : '1';
    //     }
    //     if (temp->search(str))
    //         vec.push_back(str);
    // }

    // cout << "Answer = ";
    // for (int i = 0; i < vec.size(); i++)
    //     cout << vec[i] << "     ";

    temp->traversingTrie();
    cout<<"Answer =  ";
    for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<"     ";

    return 0;
}