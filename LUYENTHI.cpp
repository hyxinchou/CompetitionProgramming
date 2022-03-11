#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define int int64_t
void solve() {
    int N, C; std::cin >> N >> C;
    std::vector<std::pair<int, int>> A(N);
    for (auto &a : A) {
        std::cin >> a.first >> a.second;
    }
    std::sort(all(A));
    int answer = 0;
    for (int i = 0; i < N; ++i) {
        if (C >= A[i].first) {
            C += A[i].second;
            ++answer;
        } else {
            break;
        }
    }
    std::cout << answer << "\n";
}

signed main() {
    solve();
    return 0;
}