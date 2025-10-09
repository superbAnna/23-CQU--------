#include<bits/stdc++.h>
using namespace std;

int n;
unordered_map<int, vector<int>> tree; // id->{type, zhi1, zhi2}

bool get_ans(const string& s, int &idx, int root_id){
    if(root_id==0){
        if(s[idx++]=='1') return true;
        else return false;
    }

    int type=tree[root_id][0];
    if(type==3){
        return !get_ans(s, idx, tree[root_id][1]);
    } else if(type==2){
        bool l=get_ans(s, idx, tree[root_id][1]);
        bool r=get_ans(s, idx, tree[root_id][2]);
        return l || r;
    } else{
        bool l=get_ans(s, idx, tree[root_id][1]);
        bool r=get_ans(s, idx, tree[root_id][2]);
        return l && r;
    }
}

int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        int type, zhi1, zhi2;
        cin>>type;
        if(type<3){
            cin>>zhi1>>zhi2;
            tree[i]={type, zhi1, zhi2};
        }else{
            cin>>zhi1;
            tree[i]={type, zhi1};
        }
    }
    // cout<<tree[1].size()<<endl;

    int start=0;
    vector<bool> is_source(n+1, true);
    for(int i=1;i<=n;i++){
        for(int j=1;j<tree[i].size();j++){
            is_source[tree[i][j]]=false;
        }
    }
    for(int i=1;i<=n;i++){
        if(is_source[i]){
            start=i;
            break;
        }
    }
    // cout<<start<<endl;

    int k;
    cin>>k;
    string s;
    for(int i=0;i<k;i++){
        cin>>s;
        int idx=0;
        bool ans = get_ans(s, idx, start);
        if(ans) cout<<"Ai"<<endl;
        else cout<<"BuAi"<<endl;
    }
}
