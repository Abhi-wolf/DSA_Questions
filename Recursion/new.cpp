#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'findSubstring' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. STRING s
 *  2. INTEGER k
 */

string findSubstring(string s, int k) {
    
    vector<int>num;
    int count=0;
    char ch[5]={'a','e','i','o','u'};
    for(int i=0;i<s.length();i++)
    {
        for(int j=i;j<(k+i);j++)
        {
            for(int n=0;n<5;n++)
            {
                if(s[j]==ch[n])
                 count++;
            }
        }
        num.push_back(count);
    }
    
    int m=num[0];
    int a=0;
    for(int i=1;i<num.size();i++)
    {
        if(num[i]>m)
        {
         m=num[i];
         a=i;
        }
    }
    vector<char> str9;
    for(int i=a;i<a+k;i++)
     str9[]=s[i];
     
    return str9;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string k_temp;
    getline(cin, k_temp);

    int k = stoi(ltrim(rtrim(k_temp)));

    string result = findSubstring(s, k);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
