#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin>>n>>m;
    vector<vector<int>> pic(n, vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>pic[i][j];
        }
    }

    vector<vector<int>> pic_new=pic;
    for(int i=1;i<n-1;i++){
        for(int j=1;j<m-1;j++){
            float sum=pic[i][j] + pic[i-1][j] + pic[i+1][j] + pic[i][j-1] + pic[i][j+1];
            pic_new[i][j]=round(sum/5);
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m-1;j++){
            cout<<pic_new[i][j]<<" ";
        }
        cout<<pic_new[i][m-1]<<" "<<endl;
    }
}
