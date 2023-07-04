#include <iostream>
#include <set>
using namespace std;

//  count of total distinct substrings of string possible
// str = ab  --> substrings possible = a, b, ab
// str= ababa --> substrings possible = a, b, ab, ba, aba, bab, abab, baba, ababa

class Node
{
public:
    Node *children[26];

    Node()
    {
        for (int i = 0; i < 26; i++)
            children[i] = NULL;
    }
};

int main()
{
    string str = "kxiksxjecwmkwabhsl";

    Node *root = new Node();

    int cnt = 0;

    for (int i = 0; i < str.length(); i++)
    {
        Node *p = root;
        for (int j = i; j < str.length(); j++)
        {
            int ind = str[j] - 'a';
            if (p->children[ind] == NULL)
            {
                p->children[ind] = new Node();
                cnt++;
            }
            p = p->children[ind];
        }
    }

    cout << "ans = " << cnt << endl;
    return 0;
}