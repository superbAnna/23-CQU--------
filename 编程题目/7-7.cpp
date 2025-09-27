#include<iostream>
using namespace std;

int main(){
    string s;
    cin>>s;

    int cnt=0;
    int ans=0;
    bool flag=false;
    for(int i=0;i<s.size();i++){
        if(flag && s[i]=='A'){
            cnt++;
            ans=max(ans, cnt);
        } else if(!flag && s[i]=='A'){
            cnt++;
            ans=max(ans, cnt);
            flag=true;
        } else if(flag && s[i]!='A'){
            flag=false;
            cnt=0;
        }
    }
    cout<<ans;
}
