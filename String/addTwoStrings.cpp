#include <bits/stdc++.h>
using namespace std;

/*
    Given two numbers as strings s1 and s2. Calculate their Product.
    Note: The numbers can be negative and You are not allowed to use any built-in function or convert
    the strings to integers. There can be zeros in the begining of the numbers.
    Eg :- s1="12345" s2="-12345"
    Eg :- s1="-123"  s2="-5678"
*/

// FIRST METHOD
string sum(string s1, string s2)
{
    string ans = "";
    int i, j;

    if (s1.size() < s2.size())
        swap(s1, s2);

    i = s1.size() - 1;
    j = s2.size() - 1;
    int car = 0;

    for (; j >= 0; j--)
    {
        int x = s1[i] - '0';
        int y = s2[j] - '0';
        int z = x + y + car;
        // cout << z << "  ";
        car = z / 10;
        z = z % 10;
        char a = (char)z + 48;
        // cout<<a<<" , ";
        ans.push_back(a);
        // car /= 10;
        i--;
    }

    while (i >= 0)
    {
        int x = s1[i] - '0';
        int s = x + car;
        // cout << s << ",  ";
        char a = (char)(s % 10) + 48;
        car = s / 10;
        ans.push_back(a);
        i--;
    }

    if (car > 0)
    {
        char a = (char)car + 48;
        ans.push_back(a);
    }

    reverse(ans.begin(), ans.end());
    // cout << endl << ans << endl;

    return ans;
}

string mul(string s1, int x, int y)
{
    string ans1 = "";
    for (int i = 0; i < y; i++)
    {
        ans1.push_back('0');
    }

    int car = 0;
    for (int i = s1.size() - 1; i >= 0; i--)
    {
        int num = s1[i] - '0';
        int m = num * x + car;
        car = m / 10;
        m = m % 10;
        char z = (char)m + 48;
        ans1.push_back(z);
    }

    if (car > 0)
    {
        char a = (char)car + 48;
        ans1.push_back(a);
    }

    reverse(ans1.begin(), ans1.end());
    return ans1;
}

string mulTwoStrings(string s1, string s2)
{
    string res = "";
    int neg = 0;
    //  REMOVED LEADING ZEROES
    string p1 = "";
    int i = 0;
    if (s1[i] == '-')
    {
        neg++;
        i++;
    }
    while (s1[i] == '0')
    {
        i++;
    }
    for (; i < s1.size(); i++)
    {
        p1 += s1[i];
    }
    s1 = p1;

    p1 = "";
    i = 0;
    if (s2[i] == '-')
    {
        neg++;
        i++;
    }
    while (s2[i] == '0')
    {
        i++;
    }
    for (; i < s2.size(); i++)
    {
        p1 += s2[i];
    }
    s2 = p1;

    cout << s1 << ",  " << s2 << endl;

    if (s1.size() == 0 || s2.size() == 0)
        return "0";

    if (s1.size() < s2.size())
        swap(s1, s2);

    int lastZeroes = 0;
    for (int j = s2.size() - 1; j >= 0; j--)
    {
        int x = s2[j] - '0';
        string a1 = mul(s1, x, lastZeroes);
        // cout<<"a1= "<<a1<<", s1="<<s1<<", x="<<x<<endl;
        res = sum(res, a1);
        // cout<<"res = "<<res<<endl;
        lastZeroes++;
    }

    if (neg % 2 != 0)
    {
        res.insert(0, "-");
    }
    return res;
}

// SECOND METHOD
string multiply(string s1, string s2)
{

    if (s1 == "0" || s2 == "0")
        return "0";
    string s1n = "";
    string s2n = "";

    if (s1[0] == '-')
    {
        s1n = "-";
        s1 = s1.substr(1);
    }
    if (s2[0] == '-')
    {
        s2n = "-";
        s2 = s2.substr(1);
    }

    // if both negative just empty the string
    if (s2n == "-" && s1n == "-")
        s1n = s2n = "";

    int n = s1.size();
    int m = s2.size();
    string res(n + m, '0');

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = m - 1; j >= 0; j--)
        {
            int num = (s1[i] - '0') * (s2[j] - '0') + (res[i + j + 1] - '0'); // res will store carry
            res[i + j + 1] = num % 10 + '0';
            res[i + j] += num / 10; // carry
        }
    }

    int i = 0;
    while (i < res.size() && res[i] == '0')
        i++;
    return s1n + s2n + res.substr(i);
}

//  MAIN FUNCTION
int main()
{
    string s1 = "9999";
    string s2 = "-9999";
    string r = "";
    // r = sum(s1, s2);
    // cout << "result = " << res << endl;
    // r = mul(s1, 2, 0);
    // cout << r << endl;

    r = mulTwoStrings(s1, s2);
    cout << "first method = " << r << endl;

    r = multiply(s1, s2);
    cout << "second method = " << r << endl;
    return 0;
}