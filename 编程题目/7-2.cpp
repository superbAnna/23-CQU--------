#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    cin>>n;
    double sum=0;
    vector<double> datas(n);
    for(int i=0;i<n;i++){
        cin>>datas[i];
        sum+=datas[i];
    }

    double avg = sum/n;
    double fc=0;
    for(double data:datas){
        fc+=((data-avg)*(data-avg));
    }
    fc=fc/(n-1);
    printf("%.2f", fc);
}
