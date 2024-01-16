#include <iostream>
#include <stack>
using namespace std;

/*
    Given a stack, the task is to sort it such that the top of the stack has the greatest element.
    Input:  Stack: 11 2 32 3 41
    Output: 41 32 11 3 2
*/

//  first recursion method
void fun(stack<int> &stk, int i)
{
    if (stk.size() - i == 1)
        return;

    int x = stk.top();
    stk.pop();
    if (x < stk.top())
    {
        int y = stk.top();
        stk.pop();
        stk.push(x);
        x = y;
    }
    fun(stk, i);
    stk.push(x);
}

void sort_stack(stack<int> &st)
{
    for (int i = 0; i < st.size(); i++)
    {
        fun(st, i);
    }
}

// second recursion method
void hepler(stack<int> &s, int num)
{
    if (s.empty() || num > s.top())
    {
        s.push(num);
        return;
    }
    int x = s.top();
    s.pop();
    hepler(s, num);
    s.push(x);
}

void sortStack(stack<int> &st)
{
    if (st.empty())
    {
        return;
    }

    int num = st.top();
    st.pop();
    sortStack(st);
    hepler(st, num);
}

int main()
{
    int arr[] = {11, 2, 32, 3, 41, 4, 9, 100};
    int n = sizeof(arr) / sizeof(arr[0]);
    stack<int> stk;
    for (int i = 0; i < n; i++)
    {
        stk.push(arr[i]);
    }
    // sort_stack(stk);
    sortStack(stk);
    while (!stk.empty())
    {
        cout << stk.top() << "      ";
        stk.pop();
    }
    return 0;
}