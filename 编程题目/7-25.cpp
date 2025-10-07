#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    int t;
    cin>>s>>t;

    vector<vector<int>> diff;
    int x=0,y=0;
    for(char c:s){
        if(c=='E') x++;
        else if(c=='S') y--;
        else if(c=='W') x--;
        else y++;
        diff.push_back({x, y});
    }

    int num, mode;
    num = t/s.size();
    mode = t%s.size()-1;
    int x_ans=num * diff[s.size()-1][0];
    int y_ans=num * diff[s.size()-1][1];
    if(mode>=0){
        x_ans+= diff[mode][0];
        y_ans+= diff[mode][1];
    }
    cout<<x_ans<<" "<<y_ans;
}
