#include<bits/stdc++.h>
using namespace std;

void check_mima(string& s){
    if(s.size()<6){
        cout<<"Your password is tai duan le."<<endl;
        return;
    }
    bool zimu=false;
    bool shuzi=false;
    for(char& c:s){
        if((c!='.'&&c<'0')||('9'<c&&c<'A')||('Z'<c&&c<'a')||c>'z'){
            cout<<"Your password is tai luan le."<<endl;
            return;
        }
        if(!zimu && (('A'<=c&&c<='Z')||('a'<=c&&c<='z'))) zimu=true;
        if(!shuzi && '0'<=c && c<='9') shuzi=true;
    }

    if(shuzi&&zimu) cout<<"Your password is wan mei."<<endl;
    else if(!shuzi&&zimu) cout<<"Your password needs shu zi."<<endl;
    else if(shuzi&&!zimu) cout<<"Your password needs zi mu."<<endl;
}

int main(){
    int n;
    cin>>n;
    string mima;
    getline(cin, mima); // 读掉换行符
    for(int idx=0;idx<n;idx++){
        getline(cin, mima);
        check_mima(mima);
    }
}
