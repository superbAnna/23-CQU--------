#include<iostream>
using namespace std;

int get_time(char pre, char now){
    if(pre==now) return 301;
    if((pre<='5' && now<='5')||(pre>'5' && now>'5')) return 210;
    return 100;
}

int main(){
    string s;
    cin>>s;

    int ans=500;
    char pre=s[0];
    for(int i=1;i<s.size();i++){
        if(s[i]=='0') s[i]='0'+10;
        ans+=get_time(pre, s[i]);
        pre=s[i];
    }
    cout<<ans;
}
