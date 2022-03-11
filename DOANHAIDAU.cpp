#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()

void solve() {
    int N; std::cin >> N;
    std::vector<int> A(N);
    for (auto &a : A) {
        std::cin >> a;
    }
    auto calc = [&] () -> int {
        int answer = 0;
        const int INF = int(1e9) + 7;
        std::vector<int> F(N + 2, N + 1);
        std::stack<std::pair<int, int>> Stack;
        for (int i = 0; i < N; ++i) {
            if (Stack.empty()) {
                Stack.push(std::make_pair(A[i], i + 1));
            } else {
                while (Stack.size() && Stack.top().first > A[i]) {
                    F[Stack.top().second] = i + 1;
                    Stack.pop();
                }
                Stack.push(std::make_pair(A[i], i + 1));
            }
        }
        for (int i = 1; i <= N; ++i) {
            std::cout << F[i] << " \n"[i == N];
        }
        std::vector<int> G(N + 2, 0);
        int mx = A[0];
        // G[0] = 1;
        G[1] = 1;
        for (int i = 1; i < N; ++i) {
            if (mx < A[i]) {
                mx = A[i];
                ++G[i + 1];
            }
            // mx = A[i];
            G[i + 1] += G[i];
        }
        for (int i = 1; i <= N; ++i) {
            std::cout << G[i] << " \n"[i == N];
        }
        for (int i = 1; i <= N; ++i) {
            answer += G[F[i] - 1] - G[i - 1];
            std::cout << i << " " << G[F[i] - 1] - G[i - 1] << "\n";
        }
        return answer;
    };
    int answer = calc();
    std::reverse(all(A));
    answer += calc();
    std::cout << answer << "\n";
}

int main() {
    solve();
    return 0;
}