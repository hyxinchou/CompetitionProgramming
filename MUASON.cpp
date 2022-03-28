#include <bits/stdc++.h>

int main() {

	int n; std::cin >> n;

	std::vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
	}

	std::vector<int> dp(100 * 1000 + 7, 0);
	dp[0] = 1;

	for (int i = 0; i < n; ++i) {
		for (int j = 100 * 1000; ~j; --j) {
			if (j + a[i] <= 100 * 1000) {
				dp[j + a[i]] |= dp[j];
			}
		}
	}

	int answer = 0;
	for (int i = 1; i <= 100 * 1000; ++i) {
		answer += dp[i];
	}

	std::cout << answer << "\n";

	return 0;
}
