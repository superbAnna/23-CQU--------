#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;

    long fac = 1;
    long ans=0;
    for(int i=1;i<=n;i++){
        fac *= i;
        ans += fac;
    }
    cout<<ans;
}
