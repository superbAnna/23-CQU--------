#include<bits/stdc++.h>
using namespace std;


int main(){
    unordered_map<char, string> map={
        {'0', "ling"},
        {'1', "yi"},
        {'2', "er"},
        {'3', "san"},
        {'4', "si"},
        {'5', "wu"},
        {'6', "liu"},
        {'7', "qi"},
        {'8', "ba"},
        {'9', "jiu"},
        {'-', "fu"}
    };
    string s;
    cin>>s;
    for(int i=0;i<s.size()-1;i++){
        cout<<map[s[i]]<<" ";
    }
    cout<<map[s[s.size()-1]];
}
