#include<iostream>
#include<unordered_map>
using namespace std;

bool is(int n){
    if(n<=1)
        return false;
    if(n<=3)
        return true;
    else{
        for(int i=2;i*i<n;i++){
            if(n%i==0){
                return false;
            }
        }
    }
    return true;
}

int main(){
    string s;
    cin>>s;

    unordered_map<char, int> map;
    for(int i=0;i<s.size();i++){
        map[s[i]] += 1;
    }
    int maxn=0,minn=200;
    for(auto it=map.begin(); it!=map.end(); it++){
        maxn=max(maxn, it->second);
        minn=min(minn, it->second);
    }
    int c=maxn-minn;
    bool flag=is(c);
    if(flag){
        cout<<"Lucky Word"<<endl<<c;
    }else{
        cout<<"No Answer"<<endl<<0;
    }
}
