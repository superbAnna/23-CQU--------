#include<bits/stdc++.h>
using namespace std;

int n, temp;
vector<int> mid;
unordered_map<int, int> mid_map;
vector<int> post;

struct TreeNode {
    int v;
    TreeNode *l;
    TreeNode *r;
    TreeNode(int x) : v(x), l(nullptr), r(nullptr) {}
};

// 构建树：[ml, mr) 是中序区间，[pl, pr) 是后序区间
TreeNode* build(int ml, int mr, int pl, int pr) {
    if (ml >= mr || pl >= pr) return nullptr;

    int root_val = post[pr - 1];
    TreeNode* root = new TreeNode(root_val);

    int root_idx = mid_map[root_val];
    int left_size = root_idx - ml;

    root->l = build(ml, root_idx, pl, pl + left_size);
    root->r = build(root_idx + 1, mr, pl + left_size, pr - 1);

    return root;
}

void get_ans(vector<int> &L, vector<int> &R, TreeNode* root) {
    if (!root) return;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int size = q.size();
        // for循环实现逐层弹出
        for (int i = 0; i < size; ++i) {
            TreeNode* node = q.front();
            q.pop();

            if (i == 0) L.push_back(node->v);      // 每层第一个：左视图
            if (i == size - 1) R.push_back(node->v); // 每层最后一个：右视图

            // 下一层，非空子树入队
            if (node->l) q.push(node->l);
            if (node->r) q.push(node->r);
        }
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        mid.push_back(temp);
        mid_map[temp] = i;
    }
    for (int i = 0; i < n; i++) {
        cin >> temp;
        post.push_back(temp);
    }

    TreeNode* root = build(0, n, 0, n);

    vector<int> L, R;
    get_ans(L, R, root);

    cout << "R: ";
    for (int i = 0; i < (int)R.size(); ++i) {
        if (i > 0) cout << " ";
        cout << R[i];
    }
    cout << endl;

    cout << "L: ";
    for (int i = 0; i < (int)L.size(); ++i) {
        if (i > 0) cout << " ";
        cout << L[i];
    }
    cout << endl;
}
