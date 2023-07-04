#include <stdio.h>
#include <stdlib.h>


//  STACK -- LIFO (last in first out)
//  IMPLEMENTATION OF STACK USING ARRAY AND STRUCTURE

struct stack
{
    int size;
    int top;
    int *S;
};



//  CREATING A STACK
void Create(struct stack *st)
{
    printf("Enter the size : ");
    scanf("%d", &st->size);
    st->top = -1;
    st->S = (int *)malloc(st->size * sizeof(int));
}



//  DISPLAYING STACK
void Display(struct stack st)
{
    int i;
    for (i = st.top; i >= 0; i--)
    {
        printf("%d  ", st.S[i]);
    }
    printf("\n");
}



//  PUSH(INSERT) OPERATION IN STACK
void Push(struct stack *st, int x)
{
    if (st->top == st->size - 1)
        printf("Stack Overflow\n");
    else
    {
        st->top++;
        st->S[st->top] = x;
    }
}




//  POP(DELETE) OPERATION IN STACK
int Pop(struct stack *st)
{
    int x = -1;
    if (st->top == -1)
        printf("Stack Underflow\n");
    else
    {
        x = st->S[st->top];
        st->top--;
    }
    return x;
}



//  GETTING ELEMENT AT AN INDEX
/* 
    pos       index = (top-index+1)
     1          3
     2          2
     3          1
     4          0
*/
int Peek(struct stack st,int index)
{
    int x=-1;
    if(st.top-index+1 < 0)
        printf("Invalid Index\n");
    x=st.S[st.top-index+1];

    return x;
}



//  CHECKS IS THE STACK EMPTY
int IsEmpty(struct stack st)
{
    if(st.top==-1)
        return 1;
    return 0;
}


//  GETTING TOP MOST ELEMENT OF STACK
int Stacktop(struct stack st)
{
    if(!IsEmpty(st))
        return st.S[st.top];
    return -1;
}





//  MAIN FUNCTION
int main()
{
    struct stack st;
    Create(&st);

    Push(&st, 10);
    Push(&st, 20);
    Push(&st, 30);
    Push(&st, 40);
    Push(&st, 50);
    Push(&st, 60);

    Display(st);

    printf("Deleted item is %d \n", Pop(&st));
    Display(st);

    printf("Deleted item is %d \n", Pop(&st));
    Display(st);

    printf("Element at index 3 is %d \n",Peek(st,3));

    if(IsEmpty(st))
        printf("Yes Stack is Empty\n");
    else
        printf("Stack is not empty\n");


    printf("Top most element of stack is %d \n",Stacktop(st));
    
    
    return 0;
}
