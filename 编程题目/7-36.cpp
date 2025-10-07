#include<bits/stdc++.h>
using namespace std;

int main(){
    int pa, pb;
    cin>>pa>>pb;
    bool p1, p2, p3;
    cin>>p1>>p2>>p3;

    int cntb=0;
    if(p1) cntb++;
    if(p2) cntb++;
    if(p3) cntb++;

    if(pa>pb){
        if(!(p1&&p2&&p3)){
            cout<<"The winner is a: "<<pa<<" + "<<3-cntb;
        } else{
            cout<<"The winner is b: "<<pb<<" + "<<cntb;
        }
    } else{
        if(p1||p2||p3){
            cout<<"The winner is b: "<<pb<<" + "<<cntb;
        } else{
            cout<<"The winner is a: "<<pa<<" + "<<3-cntb;
        }
    }
}
