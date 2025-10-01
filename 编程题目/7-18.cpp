#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    unordered_map<char, int> map;
    for(int i=0;i<26;i++){
        int temp;
        cin>>temp;
        map['a'+i]=temp;
    }

    int score=0;
    vector<int> cnt(26, 0);
    for(char c:s){
        score += map[c];
        cnt[c-'a']++;
    }

    for(int i=0;i<25;i++){
        cout<<cnt[i]<<" ";
    }
    cout<<cnt[25]<<endl;
    cout<<score;
}
