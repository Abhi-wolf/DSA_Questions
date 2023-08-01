#include <iostream>
#include <stack>
#include <math.h>
using namespace std;

// Delete middle element of stack
//  first function
void insert1(stack<int> &st, int mid)
{
    if (mid == st.size())
    {
        st.pop();
        return;
    }

    int last = st.top();
    st.pop();
    insert1(st, mid);
    st.push(last);
}


//  second function
void insert2(stack<int>&st,int mid) {
    if(mid==1) {
        st.pop();
        return;
    }

    int last=st.top();
    st.pop();
    insert2(st,mid-1);
    st.push(last);
}
void deleteMid(stack<int> &stk)
{
    int mid = 0;
    if (stk.size() % 2 == 0)
        mid = stk.size() / 2;
    else
        mid = (stk.size() + 1) / 2;

    cout << "mid=" << mid << endl;
    insert2(stk, mid);
}

void print(stack<int>st)
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
    int arr[] = {1, 2, 3, 4, 5,6};
    int size = sizeof(arr) / sizeof(arr[0]);
    stack<int> stk;
    for (int i = 0; i < size; i++)
    {
        stk.push(arr[i]);
    }
    print(stk);
    deleteMid(stk);
    print(stk);
    return 0;
}