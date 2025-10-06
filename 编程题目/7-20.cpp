#include <bits/stdc++.h>
using namespace std;

// 关键点：这里需要传递地址，否则将有大量数据复制
bool cmp(vector<int>& vec1, vector<int>& vec2){
    return vec1[0]>vec2[0];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin>>n>>m>>k;
    vector<vector<int>> data;
    vector<vector<int>> input(n, vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>input[i][j];
            data.push_back({input[i][j], i, j});
        }
    }

    sort(data.begin(), data.end(), cmp);

    int cnt=0;
    vector<bool> r_alive(n, true);
    vector<bool> c_alive(m, true);
    for(int idx=0;cnt<k && idx<m*n;idx++){
        int r = data[idx][1];
        int c = data[idx][2];
        if(r_alive[r] && c_alive[c]){
            cnt++;
            r_alive[r]=false;
            c_alive[c]=false;
        }
    }

    int c_last=0;
    for(int j=m-1;j>=0;j--){
        if(c_alive[j]){
            c_last=j;
            break;
        }
    }

    for(int i=0;i<n;i++){
        if(!r_alive[i]) continue;
        for(int j=0;j<=c_last;j++){
            if(c_alive[j]){
                if(j==c_last)
                    cout<<input[i][j]<<endl;
                else
                    cout<<input[i][j]<<" ";
            }
        }
    }
}
