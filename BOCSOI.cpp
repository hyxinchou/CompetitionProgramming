#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()

using i64 = long long;

void jiangly_fan() {
    int N, K; std::cin >> N >> K;

    std::string S; std::cin >> S;

    std::vector<std::vector<std::vector<int>>> dp(N + 7, std::vector<std::vector<int>> (N + 7, std::vector<int> (N + 7, -1)));

    std::vector<int> prefix(N + 1, 0), suffix(N + 1, 0);

    for (int i = 0; i < N; ++i) {
        if (!i) {
            prefix[i] = (S[i] == 'C' ? 1 : 0);
        } else {
            prefix[i] = prefix[i - 1] + (S[i] == 'C' ? 1 : 0);
        }
    }

    for (int i = N - 1; ~i; --i) {
        if (i == N - 1) {
            suffix[i] = (S[i] == 'C' ? 1 : 0);
        } else {
            suffix[i] = suffix[i + 1] + (S[i] == 'C' ? 1 : 0);
        }
    }

    auto DP = [&](auto self, int L, int R, int lhs, int p) -> int {
        assert(L <= R);
        if (dp[L][R][lhs] != -1) {
            return dp[L][R][lhs];
        }

        if (!p && lhs >= K) {
            return dp[L][R][lhs] = 0;
        }

        int rhs = (L - 1 < 0 ? 0 : prefix[L - 1]) + (R + 1 >= N ? 0 : suffix[R + 1]) - lhs;
        if (p && rhs >= K) {
            return dp[L][R][lhs] = 0;
        }

        if (!p) {
            return dp[L][R][lhs] = !self(self, L + 1, R, lhs + (S[L] == 'C' ? 1 : 0), p ^ 1) | !self(self, L, R - 1, lhs + (S[R] == 'C' ? 1 : 0), p ^ 1);
        }

        return dp[L][R][lhs] = !self(self, L + 1, R, lhs, p ^ 1) | !self(self, L, R - 1, lhs, p ^ 1);
    };

    std::cout << (DP(DP, 0, N - 1, 0, 0) ? "YES\n" : "NO\n");
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T = 1;
    // std::cin >> T;

    for (int i = 0; i < T; ++i) {
        jiangly_fan();
    }

    return 0;
}