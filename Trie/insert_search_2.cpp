#include <iostream>
using namespace std;

struct TrieNode
{
    TrieNode *children[26];
    int isLeaf;
};

struct TrieNode *getNode()
{
    struct TrieNode *hell = NULL;

    hell = new TrieNode();

    if (hell)
    {
        hell->isLeaf = 0;
        for (int i = 0; i < 26; i++)
            hell->children[i] = NULL;
    }
    return hell;
}

void insert(struct TrieNode *root, string word)
{
    TrieNode *node = root;

    for (int i = 0; i < word.length(); i++)
    {
        int index = word[i] - 'a';

        if (node->children[index] != NULL)
            node = node->children[index];

        else
        {
            node->children[index] = new TrieNode();
            node = node->children[index];
        }
    }
    node->isLeaf = 1;
}

int search(struct TrieNode *root, string word)
{
    TrieNode *node = root;

    if(word[0]-'a' > 25 || word[0]-'a'<0)
        return 0;

    for (int i = 0; i < word.length(); i++)
    {
        int index = word[i] - 'a';

        if (node->children[index] != NULL)
            node = node->children[index];

        else
            return 0;
    }

    return node->isLeaf;
}

void Delete(struct TrieNode *root, string word)
{
    TrieNode *node = root;

    for (int i = 0; i < word.length(); i++)
    {
        int index = word[i] - 'a';

        if (node->children[index] != NULL)
            node = node->children[index];

        else
            return;
    }
    node->isLeaf = 0;
}

int main()
{
    string str[5] = {"keys", "car", "cat", "komodo", "hello"};

    TrieNode *root = getNode();

    for (int i = 0; i < 5; i++)
    {
        insert(root, str[i]);
    }

    insert(root,"abhijeet");

    if (search(root, "cat"))
        cout << "found \n";
    else
        cout << "not found \n";

    Delete(root, "cat");

    if (search(root, "Abhijeet"))
        cout << "found \n";
    else
        cout << "not found \n";

    return 0;
}
