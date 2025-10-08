#include <bits/stdc++.h>
using namespace std;

int n;
unordered_map<int, vector<int>> tree;
int max_depth = -1;
vector<int> max_path;

// 使用引用 + 回溯
void dfs(int s, vector<bool>& visited, int depth, vector<int>& path) {
    path.push_back(s);
    visited[s] = true;

    // 更新最优路径
    if (depth > max_depth) {
        max_depth = depth;
        max_path = path;
    } else if (depth == max_depth && path < max_path) {
        max_path = path;
    }

    for (int next : tree[s]) {
        if (!visited[next]) {
            dfs(next, visited, depth + 1, path);
        }
    }

    // 回溯
    path.pop_back();
    visited[s] = false;  // 实际上树无环，visited 可省略，但保留也无妨
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        vector<int> temp(k);
        for (int j = 0; j < k; j++) {
            cin >> temp[j];
        }
        // 关键优化：对子节点排序，确保 DFS 优先走编号小的分支
        sort(temp.begin(), temp.end());
        tree[i] = temp;
    }

    // 找根节点（入度为0）
    vector<bool> is_source(n, true);
    for (auto& it : tree) {
        for (int child : it.second) {
            is_source[child] = false;
        }
    }
    int start = 0;
    for (int i = 0; i < n; i++) {
        if (is_source[i]) {
            start = i;
            break;
        }
    }

    vector<bool> visited(n, false);
    vector<int> path;
    dfs(start, visited, 0, path);

    cout << max_depth + 1 << '\n';
    for (int i = 0; i < max_path.size(); ++i) {
        if (i > 0) cout << ' ';
        cout << max_path[i];
    }
    cout << '\n';

    return 0;
}
