#include<iostream>
using namespace std;

int main(){
    int n, m;
    cin>>n>>m;

    int cnt=0;
    while(n>0){
        int out;
        if(n%(m+1)!=0)
            out = n/(m+1) + 1;
        else
            out = n/(m+1);
        n -= out;
        cnt++;
    }
    cout<<cnt<<endl;
}
