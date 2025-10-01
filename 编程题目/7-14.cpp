#include<iostream>
#include<vector>
using namespace std;

bool is_run(int year){
    if(year%4==0 && year%100!=0) return true;
    if(year%400==0) return true;
    return false;
}

int main(){
    int start, end;
    cin>>start>>end;

    vector<int> ans;
    for(int i=start;i<=end;i++){
        if(is_run(i)) ans.push_back(i);
    }
    for(int i=0;i<ans.size();i++){
        cout<<"  "<<ans[i];
        if((i+1)%5==0) cout<<endl;
    }
}
