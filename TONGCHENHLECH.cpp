#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()

using i64 = long long;

void jiangly_fan() {
	int N; std::cin >> N;

	std::vector<i64> A(N);
	for (auto &a : A) {
		std::cin >> a;
	}

	std::vector<std::vector<i64>> dp(N + 1, std::vector<i64> (2, 0));

	for (int i = 1; i < N; ++i) {
		dp[i][0] = std::max({dp[i][0], dp[i - 1][0] + std::abs(A[i] - A[i - 1]), dp[i - 1][1] + std::abs(A[i] - 1)});
		dp[i][1] = std::max({dp[i][1], dp[i - 1][0] + std::abs(1 - A[i - 1]), dp[i - 1][1]});
	}

	std::cout << std::max(dp[N - 1][0], dp[N - 1][1]) << "\n";
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