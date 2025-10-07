#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> xinqing(24);
    for(int i=0;i<24;i++){
        cin>>xinqing[i];
    }
    while(true){
        int time;
        cin>>time;
        if(time<0 || 23<time) break;
        if(xinqing[time]>50) cout<<xinqing[time]<<" "<<"Yes"<<endl;
        else cout<<xinqing[time]<<" "<<"No"<<endl;
    }
}
