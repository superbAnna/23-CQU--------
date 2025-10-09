#include<bits/stdc++.h>
#include <string>
using namespace std;

int n,m;
unordered_map<string, string> belong; // 从属关系映射，反向查找父节点
unordered_map<string, vector<string>> tree; // 从属关系树

bool is_laoren(const string &s){
    // 判断一个字符串是老人的编号还是管理结点编号
    if('0'<=s[0] && s[0]<='9') return true;
    else return false;
}

int get_cnt(string& name){
    int ans=0;
    // 不能直接递归，否则会爆栈
    stack<string> stk;
    stk.push(name);
    while(!stk.empty()){
        string curr = stk.top();
        stk.pop();
        auto it = tree.find(curr);
        if(it==tree.end()) continue;
        for(string &s:it->second){
            if(is_laoren(s)){
                ans++;
            }else{
                stk.push(s);
            }
        }
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=0;i<m;i++){
        string a,b;
        cin>>a>>b;
        belong[a]=b;
        tree[b].push_back(a);
    }

    char ins;
    while(true){
        cin>>ins;
        if(ins=='T'){ // 转院或者入院
            string id, name;
            cin>>id>>name;
            auto it = belong.find(id);
            if(it!=belong.end()){ // 改签
                vector<string>& list = tree[it->second];
                auto target = find(list.begin(), list.end(), id);
                if(target!=list.end()){
                    list.erase(target);
                }
            }
            tree[name].push_back(id);
            belong[id]=name;
        } else if(ins=='Q'){ //计算老人数量
            string name;
            cin>>name;
            int ans=0;
            ans=get_cnt(name);
            cout<<ans<<endl;
        } else if(ins=='E'){ // 输入结束
            break;
        }
    }
}
