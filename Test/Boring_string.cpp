#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    //  wrong code
    int t;
    cout<<"Enter t : ";
    cin >> t;

    while (t--)
    {
        int n;
        cout<<"\n enter n : ";
        cin >> n;
        string str;
        cout<<"\n enter string : ";
        cin >> str;

        // unordered_set<string> set;
        unordered_map<string, int> map;

        for (int i = 0; i < n; i++)
        {
            unordered_set<char> set;
            string s;
            for (int j = i; j < n; j++)
            {
                char a=str[j];
                if (set.find(a) == set.end())
                {
                    s += str[j];
                    set.insert(a);
                }
                else
                    break;
            }

            if (set.size() > 1)
                map[s]++;
        }

        unordered_map<string,int>::iterator itr;

        for(itr=map.begin();itr!=map.end();itr++)
            cout<<itr->first<<"  "<<itr->second<<endl;
    }
    return 0;
}
