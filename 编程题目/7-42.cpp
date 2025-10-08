#include <bits/stdc++.h>
using namespace std;

int n, m;
int likeMat[9][9];
bool used[9];
vector<int> assign;
vector<vector<int>> results;

void dfs(int person) {
    if (person == n) {
        results.push_back(assign);
        return;
    }

    for (int book = 0; book < m; ++book) {
        if (likeMat[person][book] && !used[book]) {
            used[book] = true;
            assign.push_back(book + 1);
            dfs(person + 1);
            // 撤销选择，让for循环继续尝试下一个book
            assign.pop_back();
            used[book] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> likeMat[i][j];

    dfs(0);

    for (auto &v : results) {
        cout << "(";
        for (int i = 0; i < n; ++i) {
            cout << v[i];
            if (i != n - 1) cout << ", ";
        }
        cout << ")\n";
    }

    return 0;
}
