#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    vector<int> daxiao(n);
    for(int i=0;i<n;i++){
        cin>>daxiao[i];
    }

    int cnt=0;
    vector<int> ans(n);
    vector<int> shengyv(n, 100);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(shengyv[j]>=daxiao[i] && shengyv[j]<100){
                ans[i]=j;
                shengyv[j]-=daxiao[i];
                break;
            } else if(shengyv[j]>=daxiao[i] && shengyv[j]==100){
                ans[i]=j;
                shengyv[j]-=daxiao[i];
                cnt++;
                break;
            }
        }
    }

    for(int i=0;i<n;i++){
        cout<<daxiao[i]<<" "<<ans[i]+1<<endl;
    }
    cout<<cnt;
}
