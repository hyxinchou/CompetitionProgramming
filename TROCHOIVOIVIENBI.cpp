#include <bits/stdc++.h>

using i64 = long long;

int main() {

	int N, M; std::cin >> N >> M;

	i64 b; std::cin >> b;

	std::vector<std::vector<i64>> A(N + 1, std::vector<i64> (M + 1));
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= M; ++j) {
			std::cin >> A[i][j];
		}
	}

	const i64 INF = 1E18;

	std::vector<std::vector<i64>> dp(N + 1, std::vector<i64> (M + 2));
	std::vector<std::vector<i64>> dp2(N + 1, std::vector<i64> (M + 2, INF));
	for (int i = 0; i <= M + 1; ++i) {
		dp[0][i] = b;
		dp2[0][i] = b;
	}

	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= M; ++j) {
			dp[i][j] = std::max({dp[i][j], (!A[i][j] ? std::max({dp[i - 1][j - 1] / 2 + (dp[i - 1][j - 1] % 2), dp[i - 1][j] / 2 + (dp[i - 1][j] % 2), dp[i - 1][j + 1] / 2 + (dp[i - 1][j + 1] % 2)}) : std::max({dp[i - 1][j - 1], dp[i - 1][j], dp[i - 1][j + 1]}) + A[i][j])});
		}
	}

	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= M; ++j) {
			dp2[i][j] = std::min({dp2[i][j], (!A[i][j] ? std::min({dp2[i - 1][j - 1] / 2 + (dp2[i - 1][j - 1] % 2), dp2[i - 1][j] / 2 + (dp2[i - 1][j] % 2), dp2[i - 1][j + 1] / 2 + (dp2[i - 1][j + 1] % 2)}) : std::min({dp2[i - 1][j - 1], dp2[i - 1][j], dp2[i - 1][j + 1]}) + A[i][j])});
		}
	}

	std::cout << *std::min_element(dp2[N].begin(), dp2[N].end()) << "\n";

	// for (int i = 1; i <= N; ++i) {
	// 	for (int j = 1; j <= M; ++j) {
	// 		std::cerr << dp2[i][j] << " \n"[j == M];
	// 	}
	// }
	std::cout << *std::max_element(dp[N].begin(), dp[N].end()) << "\n";

	return 0;
}
