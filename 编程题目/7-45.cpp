#include<bits/stdc++.h>
using namespace std;

int n;
int cnt=0;

void dfs(string k, int idx){
    while(idx<k.size() && k[idx]!='X') idx++;
    if(idx==k.size()){
        long num = stol(k);
        if(num%n==0)
            cnt++;
        return;
    }
    for(char i= (idx==0)? '1':'0';i<='9';i++){
        k[idx]=i;
        dfs(k, idx);
    }
}

int main(){
    string k;
    cin>>k>>n;

    int idx=0;
    dfs(k, idx);
    cout<<cnt;
}
