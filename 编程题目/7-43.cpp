#include<bits/stdc++.h>
using namespace std;

int n;
int k;
unordered_map<string, vector<string>> tree; // 家族树
string p1, p2;

// bfs找祖先
void get_ans(string& p, int depth, unordered_set<string>& ans){
    if(p=="-1"||depth==5) return;

    auto it = tree.find(p);
    if(it==tree.end()) return;

    string fu = it->second[1];
    string mu = it->second[2];
    if(fu!="-1"){
        ans.insert(fu);
        get_ans(fu, depth+1, ans);
    }
    if(mu!="-1"){
        ans.insert(mu);
        get_ans(mu, depth+1, ans);
    }
}

void check(string &p1, string &p2){
    auto it1 = tree.find(p1);
    auto it2 = tree.find(p2);
    if(it1==tree.end()||it2==tree.end()){
        cout<<"No"<<endl;
        return;
    }
    if(it1->second[0]==it2->second[0]){
        cout<<"Never Mind"<<endl;
        return;
    }
    unordered_set<string> ans1, ans2; // 祖先集合
    get_ans(p1, 1, ans1);
    get_ans(p2, 1, ans2);
    for(auto &a:ans1){
        if(ans2.count(a)){
            cout<<"No"<<endl;
            return;
        }
    }
    cout<<"Yes"<<endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=0;i<n;i++){
        string this_id, gen, fu_id, mu_id;
        cin>>this_id>>gen>>fu_id>>mu_id;
        tree[this_id]={gen,fu_id,mu_id};

        // 阴间：需要根据父母来推测性别
        auto fu_it=tree.find(fu_id);
        auto mu_it=tree.find(mu_id);
        if(fu_it==tree.end()) tree[fu_id]={"M", "-1", "-1"};
        if(mu_it==tree.end()) tree[mu_id]={"F", "-1", "-1"};
    }
    cin>>k;
    for(int i=0;i<k;i++){
        cin>>p1>>p2;
        check(p1, p2);
    }
}
