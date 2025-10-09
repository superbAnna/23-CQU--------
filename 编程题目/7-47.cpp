#include <bits/stdc++.h>
using namespace std;

long long a_bound, b_bound;
int n;
vector<long long> results;

void dfs(int pos, long long current) {
    if (pos == n) {
        if (current >= a_bound && current <= b_bound) {
            results.push_back(current);
        }
        return;
    }

    for (int digit = (pos==0)?1:0; digit <= 9; ++digit) {
        long long next_val = current * 10 + digit;

        if (next_val % (pos+1) == 0) {
            dfs((pos+1), next_val);
        }
    }
}

int main() {
    cin >> n >> a_bound >> b_bound;

    dfs(0, 0);

    if (results.empty()) {
        cout << "No Solution" << endl;
    } else {
        for (long long num : results) {
            cout << num << '\n';
        }
    }
}
