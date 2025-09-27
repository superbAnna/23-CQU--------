#include<iostream>
using namespace std;

int main(){
    string s;
    getline(cin, s);

    int l=s.size();
    for(int i=0;i<l;i++){
        // cout<<s[i]<<endl;
        if(s[i]==' '){
            s[i]='A';
        }
    }
    cout<<s;
}
