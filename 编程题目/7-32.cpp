#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;

    vector<int> ans(10, 0);
    for(char& c:s){
        ans[c-'0']++;
    }

    for(int i=0;i<ans.size();i++){
        if(ans[i]==0) continue;
        cout<<i<<":"<<ans[i]<<endl;
    }
}
