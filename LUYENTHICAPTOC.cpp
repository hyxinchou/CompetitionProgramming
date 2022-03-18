#include <bits/stdc++.h>

using i64 = long long;

int main() {

	int N, X; std::cin >> N >> X;

	std::vector<std::vector<int>> A(N + 1, std::vector<int> (X + 1));
	for (int i = 0; i < N; ++i) {
		for (int j = 1; j <= X; ++j) {
			std::cin >> A[i][j];
		}
	}

	std::vector<std::vector<int>> dp(N + 1, std::vector<int> (X + 1, 0));

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j <= X; ++j) {
			for (int k = 0; k + j <= X; ++k) {
				dp[i + 1][j + k] = std::max(dp[i + 1][j + k], dp[i][k] + A[i][j]);
			}
		}
	}

	std::cout << *std::max_element(dp[N].begin(), dp[N].end()) << "\n";

	return 0;
}
