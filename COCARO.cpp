#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()

using i64 = long long;

void jiangly_fan() {
	int n, k; std::cin >> n >> k;

	std::vector<std::vector<i64>> A(4, std::vector<i64> (n));
	for (auto &a : A) {
		for (auto &b : a) {
			std::cin >> b;
		}
	}

	std::vector<std::vector<i64>> pref_sum(4, std::vector<i64> (n + 1, 0));
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < n; ++j) {
			pref_sum[i][j + 1] = pref_sum[i][j] + A[i][j];
		}
	}

	std::vector<std::vector<std::vector<i64>>> dp(4, std::vector<std::vector<i64>> (k + 1, std::vector<i64> (n + 1, 0)));
	for (int i = 0; i < 4; ++i) {
		for (int seg = 0; seg <= k; ++seg) { // have seg-th segment
			for (int idx = 0; idx < n; ++idx) { // go to idx-th element in row i-th & have (1)
				dp[i][seg][idx + 1] = std::max(dp[i][seg][idx + 1], dp[i][seg][idx]); // if we don't take idx-th element in row
				if (seg) {
					for (int lidx = 0; lidx <= idx; ++lidx) {
						dp[i][seg][idx + 1] = std::max(dp[i][seg][idx + 1], dp[i][seg - 1][lidx] + pref_sum[i][idx + 1] - pref_sum[i][lidx]); // take it
					}
				}
			}
		}
	}

	std::vector<std::vector<i64>> dp2(5, std::vector<i64> (k + 1, 0));
	for (int i = 0; i < 4; ++i) {
		for (int seg = 0; seg <= k; ++seg) {
			for (int lseg = seg; lseg <= k; ++lseg) {
				dp2[i + 1][lseg - seg] = std::max(dp2[i + 1][lseg - seg], dp2[i][lseg] + dp[i][seg][n]);
			}
		}
	}

	std::cout << *std::max_element(all(dp2[4])) << "\n";
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