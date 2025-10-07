#include <iostream>
#include <vector>
using namespace std;

// 翻转函数
void reverse(vector<int>& A, int left, int right) {
    while (left < right) {
        swap(A[left], A[right]);
        left++;
        right--;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    M %= N; // 若 M > N，取模处理
    if (M != 0) {
        // 三次翻转法
        reverse(A, 0, N - 1);       // 整体翻转
        reverse(A, 0, M - 1);       // 翻转前 M 个
        reverse(A, M, N - 1);       // 翻转剩余的
    }

    for (int i = 0; i < N; i++) {
        if (i) cout << " ";
        cout << A[i];
    }
}
