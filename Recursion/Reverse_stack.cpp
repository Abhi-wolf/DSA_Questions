#include <iostream>
#include <stack>
using namespace std;

/*
    You are given a stack St. You have to reverse the stack using recursion.
    Example 1:
    Input:  St = {3,2,1,7,6}
    Output: {6,7,1,2,3}
*/

//    this function pops all the element currently present in stack and after poping all elements from satck
//   it push the num element into the stack and then it pushes the remaining poped elements from the stack
void Insert(stack<int> &st, int num)
{
    if (st.size() == 0)
    {
        st.push(num);
        return;
    }
    int last = st.top();
    st.pop();
    Insert(st, num);
    st.push(last);
}

void Reverse(stack<int> &stk)
{
    if (stk.size() == 0)
    {
        return;
    }

    int last = stk.top();
    stk.pop();
    Reverse(stk);
    Insert(stk, last);
}

void print(stack<int> st)
{
    while (!st.empty())
    {
        cout << st.top() << "   ";
        st.pop();
    }
    cout << endl;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6};
    int size = sizeof(arr) / sizeof(arr[0]);
    stack<int> stk;
    for (int i = 0; i < size; i++)
    {
        stk.push(arr[i]);
    }
    print(stk);
    Reverse(stk);
    print(stk);
    return 0;
}