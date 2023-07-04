/*  Geek has a list Li containing (not necessarily distinct) N words and Q queries. Each query consists
    of a string x. For each query, find how many strings in the List Li has the string x as its prefix.

Example 1:
Input:
    N = 5, Q = 5
    li[] = {'abracadabra', 'geeksforgeeks', 'abracadabra', 'geeks', 'geeksthrill'}
    query[] = {'abr', 'geeks', 'geeksforgeeks', 'ge', 'gar'}

Output: 2 3 1 3 0

Explaination:
    Query 1: The string 'abr' is prefix of two 'abracadabra'.
    Query 2: The string 'geeks' is prefix of three strings 'geeksforgeeks', 'geeks' and 'geeksthrill'.
    Query 3: The string 'geeksforgeeks' is prefix of itself present in li.
    Query 4: The string 'ge' also is prefix of three strings 'geeksforgeeeks', 'geeks', 'geeksthrill'.
    Query 5: The string 'gar' is not a prefix of any string in li.
*/
#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    char data;
    Node *children[26];
    int noOfChilds;
    bool isTerminal;
    Node(char y)
    {
        data = y;
        for (int i = 0; i < 26; i++)
            children[i] = NULL;
        noOfChilds = 0;
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
        cout << "insert\n";
        for (int i = 0; i < word.length(); i++)
        {
            int index = word[i] - 'a';
            if (p->children[index] == NULL)
            {
                p->children[index] = new Node(word[i]);
            }
             p = p->children[index];
            p->noOfChilds++;
           
        }
        // p->noOfChilds++;
        p->isTerminal = true;
    }

    int search(string word)
    {
        Node *p = root;
        for (int i = 0; i < word.length(); i++)
        {
            int index = word[i] - 'a';
            if (p->children[index] == NULL)
                return 0;

            p = p->children[index];
        }
        return p->noOfChilds;
    }
};

int main()
{
    string li[] = {"abracadabra", "geeksforgeeks", "abracadabra", "geeks", "geeksthrill"};
    string query[] = {"abr", "geeks", "geeksforgeeks", "ge", "gar"};

    vector<int> ans;
    Trie hell;
    for (auto x : li)
    {
        hell.insert(x);
    }

    int freq = 0;
    for (auto a : query)
    {
        freq = hell.search(a);
        ans.push_back(freq);
    }

    cout << "asl= " << hell.search("ge") << endl;

    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << "     ";

    return 0;
}