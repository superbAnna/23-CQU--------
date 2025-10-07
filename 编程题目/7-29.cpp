#include<bits/stdc++.h>
using namespace std;

int main(){
    string now;
    int pass;
    cin>>now>>pass;

    int h, m;
    if(now.size()==4){
        h=(now[0]-'0')*10 + (now[1]-'0');
        m=(now[2]-'0')*10 + (now[3]-'0');
    } else{
        h=(now[0]-'0');
        m=(now[1]-'0')*10 + (now[2]-'0');
    }

    int all = h*60 + m + pass;
    h=all/60;
    m=all%60;
    if(m>=10)
        cout<<h<<m;
    else
        cout<<h<<0<<m;
}
