#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>



struct Node
{
    int data;
    struct Node *next;
}*front=NULL,*rear=NULL;





void Enqueue(int x)
{
    struct Node *t=(struct Node *)malloc(sizeof(struct Node));
    if(t==NULL)
        printf("Queue Overflow\n");
    else
    {
        t->data=x;
        t->next=NULL;

        if(front==NULL)
            front=rear=t;
        else
        {
            rear->next=t;
            rear=t;
        }
    }
}





bool isEmpty()
{
    if(front==NULL)
        return true;
    return false;
}



int Dequeue()
{
    int x=-1;
    struct Node *t;
    if(isEmpty())
        printf("Queue is Empty\n");
    else
    {
        t=front;
        front=front->next;
        x=t->data;
        free(t);
    }
    return x;
}






void Display()
{
    struct Node *t=front;
    while(t!=NULL)
    {
        printf("%d  ",t->data);
        t=t->next;
    }
    printf("\n");
}





int main()
{
    Enqueue(10);
    Enqueue(20);
    Enqueue(30);
    Enqueue(40);
    Enqueue(50);

    Display();

    printf("Deleted item is %d\n",Dequeue(front));
    printf("Deleted item is %d\n",Dequeue(front));

    Display();
    return 0;
}