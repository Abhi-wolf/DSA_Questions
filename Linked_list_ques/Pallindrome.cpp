#include <iostream>
#include <vector>
using namespace std;


/* 
    Given a singly linked list of size N of integers. The task is to check if the given linked list is palindrome or not.  

    Pallindrome is a word, phrase, or sequence that reads the same backwards as forwards, e.g. madam or nurses run.
    Eg:- 123321 , 1234321 , madam etc

    Input:
    N = 3
    value[] = {1,2,1}

    Output: 1
    Explanation: The given linked list is
    1 2 1 , which is a palindrome and
    Hence, the output is 1.
*/


class Node 
{
    public:
        int data;
        struct Node *next;
    Node(int d)
    {
        this->data=d;
        this->next=NULL;
    }
};




//  Insertion at the front
void InsertAtHead(Node *&head,Node *&tail,int x)
{
    Node *t=new Node(x);

    if(head==NULL)
    {
        head=t;
        tail=t;
    }
    else
    {
        t->next=head;
        head=t;
    }
}




//  Insertion at the end
void InsertAtTail(Node *&head,Node *&tail,int x)
{
    Node *t=new Node(x);

    if(tail==NULL)
    {
        head=tail=t;
    }

    else
    {
        tail->next=t;
        tail=t;
    }
}



//  Display node of linked list 
void Display(Node *head)
{
    Node *p=head;
    if(p==NULL)
        cout<<"List empty\n";
    else
    {
        while(p!=NULL)
        {
            cout<<p->data<<"  ";
            p=p->next;
        }
        cout<<endl;
    }
}



//  Count no of nodes
int getLength(Node *head)
{
    Node *p=head;
    int len=0;
    while(p!=NULL)
    {
        p=p->next;
        len++;
    }
    return len;
}





/*          CHECKING PALLINDROME USING ARRAY
    FIRST COPPIED ALL DATA FROM LL TO A VECTOR AND THEN COMPARED FIRST AND
    LAST DATAS FROM ARRAY UNTIL FIRST POINTER REACHES LAST AND LAST POINTER 
    REACHES 0
*/

/*
bool checkPallindrome(vector <int>arr)
{
    int size=arr.size();
    int first=0;
    int last=size-1;

    while(first <= last)
    {
        if(arr[first] == arr[last])
        {
            first++;
            last--;
        }

        else
            return false;
    }
    return true;
}


bool isPallindrome(Node *head)
{
    vector <int> vec;
    Node *t=head;
    while(t!=NULL)
    {
        vec.push_back(t->data);
        t=t->next;
    }
    
    return checkPallindrome(vec);
}

*/


/*      CHECKING PALLINDROME USING LINKED LIST ONLY
    FOUND MIDDLE OF THE LL AND REVERSE HALF OF LL AND THEN COMPARED BOTH THE HALVES
      TIME = O(n)  SPACE = O(1)
*/


//  Gets middle mode 
Node* getMiddle(Node *head)
{
    Node *slow=head;
    Node *fast=head->next;

    while(fast!=NULL && fast->next!=NULL)
    {
        fast=fast->next->next;
        slow=slow->next;
    }
    return slow;
}


//  Reversing given linked list
Node* Reverse(Node *head)
{
    Node *p=head;
    Node *q=NULL;
    Node *r=NULL;

    while(p!=NULL)
    {
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }
    return q;
}



//  check if the linked list is pallindrome or not
bool isPallindrome(Node *head)
{
    //  if there is only one node
    if(head->next==NULL)
        return true;
    
    //  get middle node
    Node *middle=getMiddle(head);

    // reverse linked list after middle node
    Node *temp=middle->next;
    middle->next=Reverse(temp);

    // store one LL in head1 and the reversed LL after middle node in another
    Node *head1=head;
    Node *head2=middle->next;

    //  compare both the linked list
    while(head2!=NULL)
    {
        if(head1->data != head2->data)
            return false;
        head1=head1->next;
        head2=head2->next;
    }

    // reverse the LL after middle node to make LL as it was before
    temp=middle->next;
    middle->next=Reverse(temp);

    return true;
}







int main()
{
    Node *head=NULL;
    Node *tail=NULL;

    InsertAtHead(head,tail,2);
    InsertAtHead(head,tail,1);
    InsertAtTail(head,tail,3);
    InsertAtTail(head,tail,4);
    InsertAtTail(head,tail,3);
    InsertAtTail(head,tail,2);
    InsertAtTail(head,tail,1);


    Display(head);

    cout<<"Length = "<<getLength(head)<<endl;

    if(isPallindrome(head))
        cout<<"Yes Pallindrome\n";
    else
        cout<<"Not Pallindrome\n";

    Display(head);
    return 0;
}