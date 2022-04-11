#include <bits/stdc++.h>

using i64 = long long;

int main() {
	
	int n, x;
	std::cin >> n >> x;
	
	std::vector<int> C(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> C[i];
	}
	
	constexpr int P = 1E9 + 7;
	
	std::vector<int> dp(x + 1, 0);
	
	dp[0] = 1;
	
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j <= x - C[i]; ++j) {
			dp[C[i] + j] = ((dp[C[i] + j] % P) + (dp[j] % P)) % P;
		}
	}
	
	std::cout << dp[x] << "\n";
	
	return 0;
}
