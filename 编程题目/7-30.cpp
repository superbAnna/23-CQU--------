#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int all=150;
    vector<vector<int>> ans;
    for(int i=1;i<=12;i++){
        ans.push_back({i, 50-4*i, 50+3*i});
    }

    // 这里直接用min函数会报错
    int num = (n<ans.size())?n:ans.size();
    for(int i=0;i<num;i++){
        cout<<ans[i][0]<<" "<<ans[i][1]<<" "<<ans[i][2]<<endl;
    }
}
