#include <iostream>
#include <unordered_map>
using namespace std;

//  Question --> Count occurences of anagram in a string

/*  anagrams --> An anagram is a word or phrase formed by rearranging the letters of a different word
                    or phrase, typically using all the original letters exactly once.
            letters can be in any order
    Example : txt = forxxorfxdofr
              pat = for
              no of anagrams = 3

              txt = aabaabaa
              pat = aaba
              no of anagrams = 4
*/

int Count_Anagrams(string txt, string pat)
{
    unordered_map<char, int> um;
    int k = pat.size();
    int i = 0, j = 0;
    int count = 0, ans = 0;

// Count the frequency of characters in the pattern and store in the map
    for (int i = 0; i < k; i++)
        um[pat[i]]++;

 // Count the number of unique characters in the pattern
    count=um.size();

    while (j < txt.size())
    {
        if (um.find(txt[j]) != um.end())
        {
            // Decrement the frequency of txt[j] in the map
            um[txt[j]]--;

            // If the frequency becomes zero, decrement the count of unique characters
            if (um[txt[j]] == 0)
                count--;
        }

        // If the window size is less than k, expand the window
        if ((j - i + 1) < k)
            j++;


        // If the window size is equal to k, slide the window and check for pattern match
        else if ((j - i + 1) == k)
        {
            // If all unique characters in the pattern are matched, increment the answer
            if (count == 0)
                ans++;

            // Exclude txt[i] from calculations
            if (um.find(txt[i]) != um.end())
            {
                // Increment the frequency of txt[i] in the map
                um[txt[i]]++;

                // If the frequency becomes 1, increment the count of unique characters
                if (um[txt[i]] == 1)
                    count++;
            }

            // Slide the window by incrementing i and j
            i++;
            j++;
        }
    }
    return ans;
}

int main()
{
    string txt = "forxxorfxdfro";
    string pat = "for";

    int ans = Count_Anagrams(txt, pat);
    cout << "number of anagrams = " << ans << endl;
    return 0;
}
