#include <iostream>
using namespace std;

class TrieNode
{
public:
    char data;
    TrieNode *children[26];     //  there can be 26 different characters (a-z) 
    bool isTerminal;            //  represents the last character or ending of a word

    TrieNode(char ch)
    {
        this->data = ch;
        for (int i = 0; i < 26; i++)
            children[i] = NULL;

        isTerminal = false;
    }
};

class Trie
{
public:
    TrieNode *root;

    Trie()
    {
        root = new TrieNode('\0');
    }

    void InsertUtil(TrieNode *root, string word)
    {
        // base case
        if (word.length() == 0)
        {
            root->isTerminal = true;
            return;
        }

        //  assumpting all words are in small case
        int index = word[0] - 'a';
        TrieNode *child;

        // present
        if (root->children[index] != NULL)
            child = root->children[index];

        // absent
        else
        {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        InsertUtil(child, word.substr(1));
    }

    //  time complexeity = O(l) --> l=length of string
    void insert(string word)
    {
        InsertUtil(root, word);
    }

    bool searchUtil(TrieNode *root, string word)
    {
        // base case
        if (word.length() == 0)
        {
            return root->isTerminal;
        }

        int index = word[0] - 'a';
        TrieNode *child;

        // present
        if (root->children[index] != NULL)
        {
            child = root->children[index];
        }
        // absent
        else
            return false;

        return searchUtil(child, word.substr(1));
    }

    //  time complexeity = O(l) --> l=length of string
    bool searchWord(string word)
    {
        return searchUtil(root, word);
    }

    void DeleteUtil(TrieNode *root, string word)
    {
        if (word.length() == 0)
        {
            root->isTerminal = false;
            return;
        }

        int index = word[0] - 'a';
        TrieNode *child;

        if (root->children[index] != NULL)
            child = root->children[index];

        DeleteUtil(child, word.substr(1));
    }

    //  time complexeity = O(l) --> l=length of string
    //  for deletion we just have to make the terminal node to false
    //  because terminal node represents the last character of a word
    void Delete(string word)
    {
        DeleteUtil(root, word);
    }
};

int main()
{
    Trie *t = new Trie();

    t->insert("abcd");
    t->insert("abc");
    t->insert("car");
    t->insert("cat");
    t->insert("candy");

    if (t->searchWord("cat"))
        cout << "present\n";
    else
        cout << "Absent\n";

    t->Delete("cat");

    if (t->searchWord("cat"))
        cout << "present\n";
    else
        cout << "Absent\n";

    return 0;
}