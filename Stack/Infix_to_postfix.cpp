#include <iostream>
#include <string.h>
using namespace std;

// WRONG PROGRAM

struct Stack
{
    char data;
    Stack *next;
} *top = NULL;

void Push(char x)
{
    Stack *p = new Stack;
    if (p == NULL)
        cout << "Stack Overflow\n";
    else
    {
        p->data = x;
        p->next = top;
        top = p;
    }
}

char Pop()
{
    Stack *p = new Stack;
    char x = '\0';
    if (top == NULL)
        cout << "Stack Empty\n";
    else
    {
        x = top->data;
        p = top;
        top = top->next;
        delete p;
    }
    return x;
}

void Display()
{
    struct Stack *p = top;
    if (p == NULL)
        cout << "Stack Empty\n";
    else
    {
        while (p != NULL)
        {
            cout << p->data;
            p = p->next;
        }
        cout << endl;
    }
}

//  OPEARND IS THE QUANTITY ON WHICH THE OPERATION IS PERFORMED
int IsOperand(char x)
{
    if (x == '+' || x == '-' || x == '*' || x == '/')
        return 0;
    else
        return 1;
}

int Pre(char x)
{
    if (x == '+' || x == '-')
        return 1;
    else if (x == '*' || x == '/')
        return 2;
    return 0;
}

char *InfixToPostfix(char *infix)
{
    int i = 0, j = 0;
    char *postfix;
    int len = strlen(infix);
    postfix = new char[len + 2];
    while (infix[i] != '\0')
    {
        if (IsOperand(infix[i]))
            postfix[j++] = infix[i++];
        else
        {
            if (Pre(infix[i]) > Pre(top->data))
                Push(infix[i++]);
            else
                postfix[j++] = Pop();
        }
    }
    while (top != NULL)
        postfix[j++] = Pop();
    postfix[j] = '\0';
    return postfix;
}

int main()
{
    char infix[] = "a+b*c";
    Push('#');
    char *ps = InfixToPostfix(infix);
    cout << ps << endl;
    return 0;
}