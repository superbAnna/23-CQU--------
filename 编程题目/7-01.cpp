#include<iostream>
using namespace std;

bool is_lucky(string s){
    int sum1=s[0] + s[1] + s[2];
    int sum2=s[3] + s[4] + s[5];
    return sum1==sum2;
}

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        string input="";
        cin>>input;
        if(is_lucky(input))
            cout<<"You are lucky!"<<endl;
        else
            cout<<"Wish you good luck."<<endl;
    }
}
