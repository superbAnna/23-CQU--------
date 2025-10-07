#include<bits/stdc++.h>
using namespace std;

int sum(int num){
    int ans=0;
    while(num>0){
        ans+=(num%10);
        num/=10;
    }
    return ans;
}

int check(int& num){
    int chuxin=sum(num*2);
    for(int i=3;i<=9;i++){
        if(sum(num*i)!=chuxin)
            return -1;
    }
    return chuxin;
}

int main(){
    int n;
    cin>>n;
    for(int idx=0;idx<n;idx++){
        int num;
        cin>>num;
        int ans = check(num);
        if(ans<0) cout<<"NO"<<endl;
        else cout<<ans<<endl;
    }
}
