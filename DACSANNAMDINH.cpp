#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()

using i64 = long long;

void jiangly_fan() {
    int K, N, S; std::cin >> K >> N >> S;

    std::vector<std::vector<int>> AA(N, std::vector<int> (K, 0));
    for (auto &a : AA) {
        for (auto &b : a) {
            std::cin >> b;
        }
    }

    auto A = AA;
    for (int i = 0; i < K; ++i) {
        std::vector<int> Sort;

        for (int j = 0; j < N; ++j) {
            Sort.push_back(A[j][i]);
        }

        std::sort(all(Sort));

        for (int j = 0; j < N; ++j) {
            A[j][i] = Sort[j];
        }
    }

    auto dfs = [&](auto self, int u, int p, std::multiset<std::pair<int, int>> f, int sum) -> void {
        if (sum == S && u + 1 == K) {
            std::cout << "YES\n";

            for (auto [id, val] : f) {
                std::cout << val << " ";
            }

            std::cout << "\n";

            exit(0);
        }

        if (u + 1 == K) {
            return;
        }

        for (int i = 0; i < N; ++i) {
            if (A[i][u + 1] >= p) {
                if (sum + A[i][u + 1] <= S) {
                    f.insert(std::make_pair(u + 1, A[i][u + 1]));

                    self(self, u + 1, A[i][u + 1], f, sum + A[i][u + 1]);

                    f.erase(f.find(std::make_pair(u + 1, A[i][u + 1])));
                }
            }
        }
    };

    std::multiset<std::pair<int, int>> F;

    dfs(dfs, -1, 0, F, 0);

    std::cout << "NO\n";
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int T = 1;
    // std::cin >> T;

    for (int i = 0; i < T; ++i) {
        // std::cout << "Case " << i + 1 << ": ";
        jiangly_fan();
    }

    return 0;
}