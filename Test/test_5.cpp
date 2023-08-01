#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<string> splitWordsBySeparator(vector<string> &words, char separator)
{
    vector<string> ans;
    for (int i = 0; i < words.size(); i++)
    {
        string temp = "";
        for (int j = 0; j < words[i].size(); j++)
        {
            if (words[i][j] != separator)
            {
                temp += words[i][j];
            }
            else
            {
                if (temp != "")
                    ans.push_back(temp);
                temp = "";
            }
        }
        if (temp != "")
            ans.push_back(temp);
    }
    return ans;
}

long long maxArrayValue(vector<int> &nums)
{
    int j = nums.size() - 1;
    long long sum = 0;

    while (j > 0)
    {
        if (nums[j - 1] <= nums[j])
        {
            sum = (nums[j - 1] + nums[j]);
            // cout<<"num="<<nums[j-1]<<endl;
            nums[j - 1] = sum;
            
        }
        // cout<<sum<<"    ";
        j--;
    }
    return sum;
}

int main()
{
    // vector<string>vec={"one.two.three","four.five","six"};
    // vector<string> vec = {"$easy$", "$problem$"};
    // vector<string> result = splitWordsBySeparator(vec, '$');
    // for (int i = 0; i < result.size(); i++)
    // {
    //     cout << result[i] << endl;
    // }


    vector<int>v1 = {5,3,3};
    cout<<maxArrayValue(v1);

    return 0;
}