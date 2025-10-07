#include<bits/stdc++.h>
using namespace std;

int main(){
    float shengao, tizhong;
    cin>>shengao>>tizhong;

    float ans=shengao/(tizhong*tizhong);
    printf("%.1f", ans);
    if(ans>25) cout<<endl<<"PANG";
    else cout<<endl<<"Hai Xing";
}
