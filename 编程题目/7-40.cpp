#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    string head;
    cin>>head>>n;
    unordered_map<string, vector<string>> list;
    for(int i=0;i<n;i++){
        string add_this, key, add_next;
        cin>>add_this>>key>>add_next;
        list[add_this]={key, add_next};
    }

    if(n==1){
        cout<<head<<" "<<list[head][0]<<" "<<list[head][1];
        return 0;
    }

    unordered_map<string, string> key_add;
    string pre, cur=head, del_head="", del_tail="";

    while(cur!="-1"){
        string now_key = list[cur][0];
        if(now_key[0]=='-') now_key=now_key.substr(1, now_key.size()-1);
        if(key_add.count(now_key)==0){
            key_add[now_key]=cur;
            pre=cur;
            cur=list[cur][1];
        }else{
            list[pre][1]=list[cur][1];
            if(del_head=="") del_head=cur;
            if(del_tail!="")
                list[del_tail][1]=cur;
            del_tail=cur;
            cur=list[cur][1];
            list[del_tail][1]="-1";
        }
    }
    // 此时的pre就是tail
    list[pre][1]="-1";

    cur=head;
    while(cur!="-1"){
        cout<<cur<<" "<<list[cur][0]<<" "<<list[cur][1]<<endl;
        cur=list[cur][1];
    }

    cur=del_head;
    while(cur!="-1"){
        cout<<cur<<" "<<list[cur][0]<<" "<<list[cur][1]<<endl;
        cur=list[cur][1];
    }
}
