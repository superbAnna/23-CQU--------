#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, t;
    cin >> n >> t;
    vector<int> num(n);
    unordered_set<int> seen;
    
    for(int i = 0; i < n; i++) {
        cin >> num[i];
        seen.insert(num[i]);
    }
    
    for(int i = 0; i < n; i++) {
        int complement = t - num[i];
        // 使用哈希表查找，时间复杂度 O(1)
        if(seen.find(complement) == seen.end()) {
            cout << num[i] << " ";
        }
    }
    return 0;
}