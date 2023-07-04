#include <iostream>
using namespace std;



/*           Intersecthttps://practice.geeksforgeeks.org/problems/intersection-of-two-sorted-linked-lists/1?page=2&category[]=Linked%20List&sortBy=submissionsion of two sorted Linked lists

    Given two lists sorted in increasing order, create a new list representing the intersection of 
    the two lists. The new list should be made with its own memory — the original lists should not be 
    changed.  Note: The list elements are not necessarily distinct.


    Input:
    L1 = 1->2->3->4->6
    L2 = 2->4->6->8
    Output: 2 4 6
    Explanation: For the given first two
    linked list, 2, 4 and 6 are the elements
    in the intersection.
*/

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



Node* Intersection(Node *head1,Node *head2)
{
    Node *p=head1;
    Node *q=head2;

    Node *ansHead=new Node(-1);
    Node *ansTail=ansHead;

    while(p && q)
    {
        //  compares p's data and q's data if they are equal push into the new LL
        if(p->data == q->data)
        {
            InsertAtTail(ansHead,ansTail,p->data);
            p=p->next;
            q=q->next;
        }

        //  if p's data is smaller than q's data increment p
        else if(p->data < q->data)
            p=p->next;

        //  if q's data is smaller than p's data increment q
        else
            q=q->next;
    }

    // anshead == -1->2->4->5 etc   we don't need -1 so below line in written
    Node *head=ansHead->next;
    return head;
}





int main()
{
    Node *head1 = NULL;
    Node *tail1 = NULL;

    Node *head2 = NULL;
    Node *tail2 = NULL;

    InsertAtTail(head1, tail1, 1);
    InsertAtTail(head1, tail1, 2);
    InsertAtTail(head1, tail1, 3);
    InsertAtTail(head1, tail1, 4);
    InsertAtTail(head1, tail1, 8);

    InsertAtTail(head2, tail2, 1);
    InsertAtTail(head2, tail2, 2);
    InsertAtTail(head2, tail2, 6);
    InsertAtTail(head2, tail2, 8);

    Display(head1);
    Display(head2);

    Node *ans=Intersection(head1,head2);

    Display(ans);

    return 0;
}