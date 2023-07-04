#include <iostream>
#include <unordered_set>
using namespace std;


/* 
                Remove duplicates from an unsorted linked list
        LINK =   https://practice.geeksforgeeks.org/problems/remove-duplicates-from-an-unsorted-linked-list/1?page=1&category[]=Linked%20List&sortBy=submissions

    Given an unsorted linked list of N nodes. The task is to remove duplicate elements from this unsorted 
    Linked List. When a value appears in multiple nodes, the node which appeared first should be kept, all
    others duplicates are to be removed.

    Input:
    N = 4
    value[] = {5,2,2,4}
    Output: 5 2 4
    Explanation:Given linked list elements are
    5->2->2->4, in which 2 is repeated only.
    So, we will delete the extra repeated
    elements 2 from the linked list and the
    resultant linked list will contain 5->2->4
*/


struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data=x;
        next=NULL;
    }
}*first=NULL;




void insertLast(int x)
{
    //Node *t=last;
    Node *last;
    if(first==NULL)
    {
        Node *p=new Node(x);
        first=last=p;
    }
    else
    {
        Node *p=new Node(x);
        last->next=p;
        last=p;
    }
}





void Display(Node *head)
{
    Node *t=head;
    if(t==NULL)
        cout<<"List empty\n";
    else
    {
        while(t!=NULL)
        {
            cout<<t->data<<"  ";
            t=t->next;
        }
        cout<<endl;
    }
}




//  function to remove duplicates
Node *Remove_duplicates()
{
    Node *p=first;
    Node *q=NULL;
    // unordered_set - store unique elements in no particular order, and which allow for fast retrieval 
    //of individual elements based on their value.(stores in random order)
    unordered_set<int>s1;

    while(p!=NULL)
    {
        // if simliar element is found then delete the node
        if(s1.find(p->data)!=s1.end())
        {
            q->next=p->next;
            delete p;
        }

        // if similar element not found then insert element in set
        else{
            s1.insert(p->data);
            q=p;
        }
        p=q->next;
    }
    return first;
}




int main()
{
    // Node *first=NULL;
    Node *last=NULL;

    insertLast(1);
    insertLast(2);
    insertLast(3);
    insertLast(1);
    insertLast(1);
    insertLast(4);
    insertLast(5);
    
    Display(first);

    Node *p=Remove_duplicates();

    Display(p);
    return 0;
}