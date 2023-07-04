#include <iostream>
using namespace std;

class Node
{
public:
  int data;
  Node *next;
  Node(int d)
  {
    this->data = d;
    this->next = NULL;
  }
};


// function to insert at tail
void InsertAtTail(Node *&head, Node *&tail, int x)
{
  Node *t = new Node(x);
  // empty list
  if (tail == NULL)
  {
    head = tail = t;
  }

  else
  {
    tail->next = t;
    tail = t;
  }
}



//  function to count no of nodes
int getLength(Node *head)
{
  Node *p = head;
  int len = 0;
  while (p != NULL)
  {
    len++;
    p = p->next;
  }
  return len;
}



//  revrse linked list
Node *Reverse(Node *head)
{
  Node *p = head;
  Node *q = NULL;
  Node *r = NULL;
  while (p)
  {
    r = q;
    q = p;
    p = p->next;
    q->next = r;
  }
  return q;
}



//  addition function
Node *add(Node *head)
{
  Node *ansHead = NULL;
  Node *ansTail = NULL;

  //  first LL
  Node *p = head;

  // second LL having only one node
  Node *q = new Node(1);

  int carry = 0;

  while (p != NULL || q != NULL || carry != 0)
  {
    int val1 = 0;
    if (p != NULL)
      val1 = p->data;

    int val2 = 0;
    if (q != NULL)
      val2 = q->data;

    int sum = val1 + carry + val2;
    int digit = sum % 10;

    // inserting the digit without carry(hasil) in LL
    InsertAtTail(ansHead, ansTail, digit);

    //  calculating LL
    carry = sum / 10;

    if (p != NULL)
      p = p->next;

    if (q != NULL)
      q = q->next;
  }
  return ansHead;
}



// addone 1 to a number represented by LL 
Node *addOne(Node *head)
{
  //  first reversed by the number represented by LL
  head = Reverse(head);

  // second called function add to add 1 to the number
  Node *ans = add(head);

  // third revrsed the LL to print
  ans = Reverse(ans);

  return ans;
}



//  display function
void Display(Node *head)
{
  Node *t = head;

  if (head == NULL)
  {
    cout << "List empty \n";
    return;
  }

  while (t != NULL)
  {
    cout << t->data << "  ";
    t = t->next;
  }
  cout << endl;
}



// main function
int main()
{
  Node *head1, *tail1;
  head1 = tail1 = NULL;

  InsertAtTail(head1, tail1, 3);
  InsertAtTail(head1, tail1, 4);
  InsertAtTail(head1, tail1, 9);

  Display(head1);

  Node *A = addOne(head1);
  Display(A);
  return 0;
}