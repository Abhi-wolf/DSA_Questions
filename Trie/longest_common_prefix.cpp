#include <iostream>
using namespace std;

//  longest common prefix among all the given strings
//  str[] = {"codirs", "codingninja", "coding", "codizen"}  here "cod" is the substring that is the prefix of all the strings

class Node
{
public:
    char ch;
    Node *children[26];
    int childCount;  //  used to count children of that node
    bool isTerminal; //  if the node has more than one children then that character is not common to all the strings
                     //  character which is common to all the strings must have only one children
    Node(char c)
    {
        ch = c;
        for (int i = 0; i < 26; i++)
            children[i] = NULL;

        childCount = 0;
        isTerminal = false;
    }
};

class Trie
{
public:
    Node *root;
    Trie()
    {
        root = new Node('\0');
    }

    void insert(string word)
    {
        Node *p = root;
        for (int i = 0; i < word.size(); i++)
        {
            int ind = word[i] - 'a';
            if (p->children[ind] == NULL)
            {
                p->children[ind] = new Node(word[i]);
                p->childCount++;
            }

            p = p->children[ind];
        }
        p->isTerminal = true;
    }

    string lcp(string word)
    {
        Node *p = root;
        string ans = "";

        for (int i = 0; i < word.length(); i++)
        {
            char ch = word[i];

            if (p->childCount == 1)
            {
                ans += ch;
                p = p->children[word[i] - 'a'];
            }

            else
                break;

            if (p->isTerminal == true)
                break;
        }
        return ans;
    }
};

int main()
{
    string str[] = {"coders", "codingninja", "coding", "codezen"};

    //                  BRUTE FORCE
    /* string ans = "";
    string hell = str[0];

    for (int i = 0; i < hell.size(); i++)
    {
        int count = 0;
        for (int j = 0; j < 4; j++)
        {
            if (hell[i] == str[j][i])
            {
                count++;
            }
            else
            {
                break;
            }
        }
        if (count == 4)
            ans += hell[i];
    }
    cout << "answer = " << ans << endl; */

    //                  USING TRIE
    Trie hell;
    for (int i = 0; i < 4; i++)
        hell.insert(str[i]);

    string ans = hell.lcp(str[0]);
    cout << "Answer = " << ans << endl;

    return 0;
}