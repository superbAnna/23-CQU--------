#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin>>n>>m;
    vector<int> out(n);
    vector<int> in(n);
    for(int i=0;i<n;i++){
        cin>>out[i];
    }
    for(int i=0;i<n;i++){
        cin>>in[i];
    }

    int ans=0;
    for(int idx=0;idx<m;idx++){
        int opt, i, c;
        cin>>opt>>i>>c;
        if(opt==1){
            ans+=(out[i-1]*c);
        } else{
            ans-=(in[i-1]*c);
        }
    }
    cout<<ans;
}
