#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> tree(n + 1);
    int root = 0;
    
    for (int i = 1; i <= n; i++) {
        int p;
        cin >> p;
        if (p == 0) {
            root = i;
        } else {
            tree[p].push_back(i);
        }
    }
    
    for (int i = 1; i <= n; i++) {
        sort(tree[i].begin(), tree[i].end());
    }
    
    int max_degree = 0;
    for (int i = 1; i <= n; i++) {
        int deg = tree[i].size();
        if (deg > max_degree) {
            max_degree = deg;
        }
    }
    
    bool is_full = true;
    for (int i = 1; i <= n; i++) {
        int deg = tree[i].size();
        if (deg > 0 && deg != max_degree) {
            is_full = false;
            break;
        }
    }
    
    cout << max_degree;
    if (is_full) {
        cout << " yes" << endl;
    } else {
        cout << " no" << endl;
    }
    
    vector<int> preorder;
    stack<int> st;
    st.push(root);
    while (!st.empty()) {
        int node = st.top();
        st.pop();
        preorder.push_back(node);
        for (auto it = tree[node].rbegin(); it != tree[node].rend(); it++) {
            st.push(*it);
        }
    }
    
    for (int i = 0; i < preorder.size(); i++) {
        if (i > 0) cout << " ";
        cout << preorder[i];
    }
    cout << endl;
    
    return 0;
}