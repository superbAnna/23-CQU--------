#include<iostream>
using namespace std;

int main(){
    int v, n;
    cin>>v>>n;

    string min_name;
    int min_v;
    double min_jiage=999999;
    for(int i=0;i<n;i++){
        string name;
        int v_now;
        double jiage;
        cin>>name>>v_now>>jiage;
        if(v_now<=v && jiage<min_jiage){
            min_jiage=jiage;
            min_name=name;
            min_v=v_now;
        }
    }
    cout<<min_name<<" "<<min_v<<" ";
    printf("%.2f", min_jiage);
}
