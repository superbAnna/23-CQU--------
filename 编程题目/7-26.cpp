#include<bits/stdc++.h>
using namespace std;

void print(int k, char c){
    if (k==1){
        cout<<c<<endl;
        return;
    }
    for(int i=0;i<k;i++){
        string s1(i, ' ');
        string s2(2*(k-i)-1, c);
        cout<<s1+s2<<endl;
    }
    for(int i=1;i<k;i++){
        string s1(k-i-1, ' ');
        string s2(2*(i)+1, c);
        cout<<s1+s2<<endl;
    }
}

int main(){
    int n;
    char c;
    cin>>n>>c;

    int k=0;
    int all=2*k*k-1;
    while(all<n){
        k++;
        all=2*k*k-1;
    }
    if(all!=n) k--;
    print(k, c);
    cout<<n-2*k*k+1;
}
