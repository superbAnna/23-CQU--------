#include<iostream>
#include<vector>
using namespace std;

struct student{
    string name;
    int age;
    int nopi;
};

int main(){
    vector<student> cls;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        string name;
        int age;
        int nopi;
        cin>>name>>age>>nopi;
        cls.push_back({name, age, nopi});
    }

    for(int i=0;i<n;i++){
        cls[i].nopi+=cls[i].nopi/5;
        if(cls[i].nopi>600) cls[i].nopi=600;
        cout<<cls[i].name<<" "<<cls[i].age + 1<<" "<<cls[i].nopi<<endl;
    }
}
