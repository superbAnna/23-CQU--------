#include <bits/stdc++.h>
using namespace std;
bool jude(string k,int m)
{
    stack<int> t;
    for(int i=0;i<k.length();i++)
    {
        if(k[i]=='S')
        {
            if(t.size()==m) return false;
            t.push(1);
        }
        else
        {
            if(t.empty()) return false;
            t.pop();
        }
    }
    if(!t.empty()) return false; 
    return true;
}
int main()
{

    int n,m;
    cin>>n>>m;
   string f;
    for(int i=0;i<n;i++)
    {
        cin>>f;
        if(jude(f,m)){
            cout<<"YES";
        }
        else cout<<"NO";
        if(i!=n-1) cout<<endl;
    }
    return 0;

}