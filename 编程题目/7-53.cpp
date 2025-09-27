#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int> num(51,0);
    int k;
    while(n--)
    {
        cin>>k;
        num[k]++;
    }
    for(int i =0;i<51;i++){
        if(num[i])
        {
            cout<<i<<":"<<num[i]<<endl;
        }
    }
    return 0;
}