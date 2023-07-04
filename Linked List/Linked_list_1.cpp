/*
        WHAT IS A SINGLY LINKED LIST?
A Singly Linked List is a specialized case of a generic linked list. In a singly linked list, 
each node links to only the next node in the sequence, i.e if we start traversing from the first 
node of the list, we can only move in one direction(pun intended). 

    time complexity = O(n);
    space complexity = O(n);

*/
 
 

#include <iostream>
using namespace std;


//  LINKED LIST USING STRUCTURE


struct node {
    int num;
    string str;
    node *ptr;
}*first,*last,*temp;

//  INSERTION FUNCTION
void insert(int n,string s) {

    if(first==NULL) {

        first=new node;
        first->num=n;
        first->str=s;
        first->ptr=NULL;
        last=first;
    }

    else {

        temp=new node;
        temp->num=n;
        temp->str=s;
        temp->ptr=NULL;
        last->ptr=temp;
        last=temp;
        temp=NULL;
    }
}


//  DISPLAY FUNCTION
void display() {

    if(first==NULL) 
        cout<<"Empty\n";

    else {
        temp=first;
        while(temp!=NULL) {
            cout<<temp->num<<"  "<<temp->str<<endl;
            temp=temp->ptr;
        }
    }
}


//  DELETE FUNCTION
void Delete() {
    if(first==NULL) {
        cout<<"Empty\n";
    }

    else{
        temp=first;
        first=first->ptr;
        delete temp;
    }
}


//  COUNT FUNCTION
int List_count() {
    int count=0;
    temp=first;
    while(temp!=NULL) {
        count++;
        temp=temp->ptr;
    }
    return count;
}


//  MAIN FUNCTION
int main() {

    insert(10,"Hello World I am WhiteWolf");
    insert(20,"ABCD");
    insert(12,"Abhijeet Kumar");
    insert(10000,"World");

    display();
    cout<<"\nNumber of Nodes = "<<List_count()<<endl<<endl;

    Delete();
    // Delete()`;
    display();
    cout<<"\nNumber of Nodes = "<<List_count()<<endl<<endl;
    return 0;
}