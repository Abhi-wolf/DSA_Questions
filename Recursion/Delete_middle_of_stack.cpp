#include <iostream>
#include <stack>
#include <cmath>
using namespace std;

/*
    Given a stack, delete the middle element of the stack without using any additional data structure.
    Middle element:- ceil((size_of_stack+1)/2) (1-based indexing) from bottom of the stack.

    Note: The output shown by the compiler is the stack from top to bottom.

Example 1:
Input:  Stack = {10, 20, 30, 40, 50}
Output: ModifiedStack = {10, 20, 40, 50}
*/

void fun(stack<int> &s, int mid)
{
    if (mid == 0)
    {
        s.pop();
        return;
    }

    int x = s.top();
    s.pop();
    fun(s, mid - 1);
    s.push(x);
}

void fun2(stack<int> &s, int n, int index)
{
    if (index == n / 2)
    {
        s.pop();
        return;
    }

    int x = s.top();
    s.pop();
    index = index + 1;
    fun2(s, n, index);
    s.push(x);
}

void deleteMid(stack<int> &s, int sizeOfStack)
{
    int mid = ceil(sizeOfStack / 2);

    fun(s, mid);
    // fun2(s,sizeOfStack,0);
}

void print(stack<int> st)
{
    while (!st.empty())
    {
        cout << st.top() << "   ";
        st.pop();
    }
}

int main()
{
    stack<int> stk;
    int arr[] = {10, 20, 30, 40, 50};
    int size = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < size; i++)
    {
        stk.push(arr[i]);
    }
    deleteMid(stk, size);
    print(stk);
    return 0;
}