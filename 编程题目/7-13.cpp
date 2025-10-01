#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    if(n==0){
        cout<<"average = 0.00"<<endl<<"count = 0";
    }
    else{
        float sum=0;
        int cnt=0;
        for(int i=0;i<n;i++){
            int fenshu;
            cin>>fenshu;
            sum+=fenshu;
            if(fenshu>=60) cnt++;
        }
        float avg=sum/n;
        printf("average = %.2f", avg);
        cout<<endl;
        cout<<"count = "<<cnt;
    }
}
