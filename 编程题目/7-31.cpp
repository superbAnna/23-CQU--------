#include<bits/stdc++.h>
using namespace std;

bool is_int(string s){
    if(s=="") return false;
    bool res = true;
    for(char c:s){
        if('0'>c || c>'9'){
            res=false;
            break;
        }
    }
    if(s[0]=='0'||(s.size()>3 && s>"1000")) res=false;
    return res;
}

int main(){
    string s, s1, s2;
    getline(cin, s);
    for(int i=0;i<s.size();i++){
        if(s[i]==' '){
            s1=s.substr(0, i);
            s2=s.substr(i+1, s.size()-i-1);
            break;
        }
    }
    // cout<<s<<"/"<<s1<<"/"<<s2<<endl;

    bool rs1=is_int(s1), rs2=is_int(s2);
    bool rs=rs1 && rs2;
    if(rs1) cout<<s1;
    else cout<<"?";
    cout<<" + ";
    if(rs2) cout<<s2;
    else cout<<"?";
    cout<<" = ";
    if(rs)
        cout<<stoi(s1)+stoi(s2);
    else
        cout<<"?";
}
