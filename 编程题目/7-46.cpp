#include<bits/stdc++.h>
using namespace std;

bool cmp(vector<int>&event1, vector<int>&event2){
    if(event1[0]<event2[0])
        return true;
    else if(event1[0]==event2[0])
        return event1[1]>event2[1];
    else
        return false;
}

// 经典排序+线扫描
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;

    vector<vector<int>> events(n*2, vector<int>(2)); //{秒，类型}
    for(int i=0;i<n*2;i+=2){
        int h, m, s;
        char c;
        cin>>h>>c>>m>>c>>s;
        events[i]={3600*h+60*m+s, 1};
        cin>>h>>c>>m>>c>>s;
        events[i+1]={3600*h+60*m+s, -1};
    }
    sort(events.begin(), events.end(), cmp);

    int max_cnt=-1, cnt=0;
    for(int i=0;i<n*2;i++){
        cnt+=events[i][1];
        max_cnt=max(cnt, max_cnt);
    }
    cout<<max_cnt;
}
