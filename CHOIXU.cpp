#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()

using i64 = long long;

void jiangly_fan() {
	int K, L, m; std::cin >> K >> L >> m;

	while (m--) {
		int N; std::cin >> N;

		std::vector<int> dp(N + 100, 0);

		for (int i = 1; i <= N; ++i) {
			dp[i] |= ((i - K < 0 ? 0 : !dp[i - K]) || (i - L < 0 ? 0 : !dp[i - L]) || !dp[i - 1]);
		}

		std::cout << (dp[N] ? "A" : "B");
	}

	std::cout << "\n";
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