#include<bits/stdc++.h>
using namespace std;

long long int_pow(long long base, int exp){
    long long result=1;
    while(exp>0){
        if(exp&1) result*=base;
        base*=base;
        exp >>= 1;
    }
    return result;
}

int find_m(unsigned int n, int k){
    // n 为目标整数值
    // k 为给定幂次
    unsigned sum=0;
    int d=1;
    while(sum<n){
        sum+=int_pow(d, k);
        d++;
    }
    if(sum==n) return d-1;
    else return -1;
}

int main(){
    unsigned int n;
    cin>>n;

    int max_k=-1;
    int target_m;
    int res;
    for(int i=1;i<=31;i++){
        res = find_m(n, i);
        if(res!=-1){
            max_k=i;
            target_m=res;
        }
    }
    if(max_k<0)
        cout<<"Impossible for "<<n<<".";
    else{
        for(int i=1;i<=target_m-1;i++){
            cout<<i<<"^"<<max_k<<"+";
        }
        cout<<target_m<<"^"<<max_k;
    }
}
