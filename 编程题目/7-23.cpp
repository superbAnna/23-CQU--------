#include<bits/stdc++.h>
using namespace std;

int test_diff(vector<int>& taiya, int& diff_max){
    int max_taiya=-1;
    for(int i=0;i<4;i++){
        max_taiya=max(max_taiya, taiya[i]);
    }
    int cnt=0;
    int idx=-1;
    for(int i=0;i<4;i++){
        if(max_taiya-taiya[i] > diff_max){
            cnt++;
            idx=i;
        }
    }
    if(cnt==0) return -1;
    if(cnt==1) return idx+1;
    return 5;
}

int test_min(vector<int>& taiya, int& min_taiya){
    int cnt=0, idx=-1;
    for(int i=0;i<4;i++){
        if(taiya[i]<min_taiya){
            cnt++;
            idx=i;
        }
    }
    if(cnt<=1) return idx+1;
    else return 5;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> taiya(4);
    for(int i=0;i<4;i++){
        cin>>taiya[i];
    }
    int min_taiya, diff_max;
    cin>>min_taiya>>diff_max;

    int res1 = test_diff(taiya, diff_max);
    int res2 = test_min(taiya, min_taiya);
    if(res1<=0 && res2<=0)
        cout<<"Normal";
    else if(res1<=0 && res2>0 && res2<5)
        cout<<"Warning: please check #"<<res2<<"!";
    else if(res1>0 && res1<5 && res2<=0)
        cout<<"Warning: please check #"<<res1<<"!";
    else
        cout<<"Warning: please check all the tires!";
}
