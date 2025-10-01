#include<iostream>
using namespace std;

int main(){
    int n;
    char c;
    cin>>n>>c;

    int lines;
    if(n%2==0) lines=n/2;
    else lines=(n+1)/2;

    for(int i=0;i<lines;i++){
        for(int j=0;j<n-1;j++){
            cout<<c;
        }
        cout<<c<<endl;
    }
}
