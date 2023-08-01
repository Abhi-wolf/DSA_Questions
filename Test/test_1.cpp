#include <iostream>
#include <unordered_map>
#include <vector>
#include <deque>
using namespace std;


int longestValidSubstring(string word, vector<string>& forbidden) {
    unordered_map<string,int>um;

    for(int i=0;i<forbidden.size();i++) {
        um[forbidden[i]]++;
    }

    int i=0,j=0;
    deque<char>dq;
    while(j<word.size()) {
        dq.push_back(word[j]);
        if(um.find(word.substr(i,j))==um.end()) {
            j++;
        }
        else {
            cout<<word.substr(i,j)<<endl;
            dq.pop_front();
            i++;
            j++;
        }
    }
    return dq.size();
}


int main() {
    string str="cbaaaabc";
    vector<string>vec;
    vec.push_back("aaa");
    vec.push_back("cb");

    int ans=longestValidSubstring(str,vec);
    cout<<"\nanswer = "<<ans<<endl;
    return 0;
}