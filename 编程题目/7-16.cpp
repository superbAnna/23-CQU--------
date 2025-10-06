#include<iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;

    string s;
    getline(cin, s);
    for(int index=0;index<t;index++){
        getline(cin, s);
        for(char& c:s) c = tolower(c);
        // 这里必须要用string::npos
        if(s.find("shinto mekkaku") != string::npos)
            cout << "Medaka Kuroiwa" << endl;
        else
            cout << "Bonnjinn" << endl;
    }
}
