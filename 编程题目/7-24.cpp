#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    unordered_map<int, vector<long>> data(n);
    for(int i=0;i<n;i++){
        long id, kaoshi;
        int ceshi;
        cin>>id>>ceshi>>kaoshi;
        data[ceshi]={id, kaoshi};
    }

    int m;
    cin>>m;
    for(int i=0;i<m;i++){
        int ceshi_;
        cin>>ceshi_;
        cout<<data[ceshi_][0]<<" "<<data[ceshi_][1]<<endl;
    }
}
