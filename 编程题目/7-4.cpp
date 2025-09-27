#include<iostream>
using namespace std;

int main(){
    float ans = 0;
    for(int i=0;i<3;i++){
        float mn = 0;
        cin>>mn;
        ans+=mn;
        if(mn-9.9<-5e-07 && mn>0)
            ans+=0.99;
    }
    printf("%.2f", ans);
}
