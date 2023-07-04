#include <iostream>
using namespace std;

class Node
{
public:
  // char data;
  Node *children[2];
  bool isTerminal;

  Node()
  {
    // this->data = x;
    for (int i = 0; i < 2; i++)
      children[i] = NULL;

    this->isTerminal = false;
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
    p->isTerminal = true;
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
    return p->isTerminal;
  }
};

int main()
{
  int arr[5][3] = {{1, 0, 1}, {1, 1, 1}, {1, 0, 1}, {1, 1, 1}, {1, 0, 0}};

  Trie ptr;
  for (int i = 0; i < 5; i++)
  {
    string str = "";
    for (int j = 0; j < 3; j++)
    {
      if (arr[i][j] == 0)
        str += '0';
      else
        str += '1';
    }
    // cout<<str<<endl;
    if (!ptr.search(str))
    {
      ptr.insert(str);
      cout << str << endl;
    }
  }
  return 0;
}