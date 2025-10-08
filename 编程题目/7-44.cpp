#include<bits/stdc++.h>
using namespace std;

int n, k;
int max_depth=-1;
unordered_map<int, vector<int>> mymap;

void dfs(int &s, vector<bool> &visited, int depth, int &target){
    if(depth>max_depth){
        target=s;
        max_depth=depth;
    }
    visited[s]=true;
    for(int id:mymap[s]){
        if(visited[id]) continue;
        dfs(id, visited, depth+1, target);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>k;
        vector<int> temp(k);
        for(int j=0;j<k;j++){
            cin>>temp[j];
        }
        mymap[i]=temp;
    }

    // 手动计算起点
    vector<bool> is_start(n+1, true);
    for(int i=1;i<=n;i++){
        for(int &id:mymap[i]){
            is_start[id]=false;
        }
    }
    int start;
    for(int i=1;i<=n;i++){
        if(is_start[i]){
            start=i;
            break;
        }
    }

    vector<bool> visited(n+1, false);
    int depth=0, target=1;
    dfs(start, visited, depth, target);
    cout<<target;
}
