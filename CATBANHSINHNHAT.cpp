#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()

using i64 = long long;

void jiangly_fan() {
	int N, K; std::cin >> N >> K;

	std::vector<std::vector<i64>> A(N, std::vector<i64> (N, 0));
	for (auto &a : A) {
		for (auto &b : a) {
			std::cin >> b;
		}
	}

	std::vector<std::vector<i64>> pref_sum(N + 1, std::vector<i64> (N + 1, 0));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			pref_sum[i + 1][j + 1] = pref_sum[i + 1][j] + A[i][j];
		}
	}

	i64 answer = 0;

	++K;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			i64 res = 0;

			if (i + K <= N && j + K <= N) {
				for (int t = 1; t <= K; ++t) {
					res += pref_sum[i + t][j + t] - pref_sum[i + t][j];
				}
			}

			answer = std::max(answer, res);
		}
	}

	std::cout << answer << "\n";
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
