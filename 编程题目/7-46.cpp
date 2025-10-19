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

//----------------另一种解法，考虑使用差分----------------
#include<iostream>
using namespace std;
const int MAX = 60*60*24+1;
int list [MAX];

int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        int h,m,s;
        scanf("%d:%d:%d",&h,&m,&s);
        list[h*3600+m*60+s]+=1;
        scanf("%d:%d:%d",&h,&m,&s);
        list[h*3600+m*60+s+1]-=1;//注意这里的+1，因为差分是x_{n} - x_{n+1}
    }
    int ans=0;
    int max_ans=0;
    for(int i=0;i<MAX;i++)
    {
        ans+=list[i];
        if(ans>max_ans)max_ans=ans;
    }
    cout<<max_ans;
}