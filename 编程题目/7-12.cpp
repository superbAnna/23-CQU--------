#include<iostream>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;

    for(int i=0;i<n;i++){
        float jiage;
        cin>>jiage;
        if(jiage<m)
            printf("On Sale! %.1f\n", jiage);
    }
    // cout<<(10.1-10);
}
