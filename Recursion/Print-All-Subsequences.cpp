#include <iostream>
using namespace std;

/* PRINT ALL THE SUBSEQUENCES OF A STRING  
    input ="abc"
    ouput = "a", "b", "c", "ab", "bc", "ac", "abc", ""
*/




void Subsequence(string input, string output)
{
    if (input.size() == 0)
    {
        cout << output << ", ";
        return;
    }

    string out1 = output;
    string out2 = output;

    out1.push_back(input[0]);

    // take the character
    Subsequence(input.substr(1), out1);

    // do not take the character
    Subsequence(input.substr(1), out2);
}




int main()
{
    string inp = "abc";
    string out = "";
    Subsequence(inp, out);
    return 0;
}