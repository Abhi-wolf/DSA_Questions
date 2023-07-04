#include <stdio.h>
#include <stdlib.h>



struct Queue
{
    int size;
    int front;
    int rear;
    int *Q;
};


void create(struct Queue *q,int size)
{
    q->size=size;
    q->rear=q->front=-1;
    q->Q=(int *)malloc(q->size*sizeof(int));
}



void enqueue(struct Queue *q,int x)
{
    if(q->rear==q->size-1)
        printf("Queue is Full\n");
    else
    {
        q->rear++;
        q->Q[q->rear]=x;
    }
}




int dqueue(struct Queue *q)
{
    int x=-1;
    if(q->rear == q->front)
        printf("Queue is empty\n");
    else
    {
        q->front++;
        x=q->Q[q->front];
    }
    return x;
}




void Display(struct Queue q)
{
    if(q.front==q.rear)
        printf("Queue is empty\n");
    else
    {
        while(q.front!=q.rear)
        {
            q.front++;
            printf("%d  ",q.Q[q.front]);
        }
        printf("\n");
    }
}


int main()
{
    struct Queue obj;
    create(&obj,5);
    enqueue(&obj,10);
    enqueue(&obj,20);
    enqueue(&obj,30);
    enqueue(&obj,40);
    enqueue(&obj,50);

    Display(obj);

    printf("\nDeleted element is %d\n",dqueue(&obj));
    Display(obj);

    printf("\nDeleted element is %d\n",dqueue(&obj));
    Display(obj);
    return 0;
}