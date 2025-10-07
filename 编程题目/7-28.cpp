#include<bits/stdc++.h>
using namespace std;

bool is_run(int year){
    if(year%4==0 && year%100!=0) return true;
    if(year%400==0) return true;
    return false;
}

int main(){
    int y, m, d;
    char s;
    cin>>y>>s>>m>>s>>d;

    int days_in_month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (is_run(y)) days_in_month[2] = 29;

    int ans=0;
    for(int i=1;i<m;i++){
        ans+=days_in_month[i];
    }
    ans+=d;
    cout<<ans;
}
