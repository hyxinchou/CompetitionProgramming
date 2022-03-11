#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()

using i64 = long long;

void jiangly_fan() {
	int n, m; std::cin >> n >> m;

	std::vector<std::vector<int>> cost(n, std::vector<int> (n, 0));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			std::cin >> cost[i][j];
		}
	}

	std::vector<int> loc(m);
	for (auto &l : loc) {
		std::cin >> l;
		--l;
	}

	const int INF = 1E9;

	std::vector<std::vector<std::vector<int>>> dp(m + 3, std::vector<std::vector<int>> (n + 1, std::vector<int> (n + 1, INF)));

	dp[0][0][1] = 0;

	int answer = INF;

	int ___ = 2;

	for (int i = 0; i < m; ++i) {
		for (int _ = 0; _ < n; ++_) {
			for (int __ = 0; __ < n; ++__) {
				if (dp[i][_][__] ^ INF && _ ^ __ && __ ^ ___ && ___ ^ _) {
					if (_ ^ loc[i] && __ ^ loc[i]) dp[i + 1][_][__] = std::min(dp[i + 1][_][__], dp[i][_][__] + cost[___][loc[i]]);
					if (_ ^ loc[i] && ___ ^ loc[i]) dp[i + 1][_][___] = std::min(dp[i + 1][_][___], dp[i][_][__] + cost[__][loc[i]]);
					if (__ ^ loc[i] && ___ ^ loc[i]) dp[i + 1][__][___] = std::min(dp[i + 1][__][___], dp[i][_][__] + cost[_][loc[i]]);

					if (i == m - 1) {
						answer = std::min({answer, dp[i + 1][_][__], dp[i + 1][_][___], dp[i + 1][__][___]});
					}
				}
			}
		}
		___ = loc[i];
	}

	std::cout << answer << "\n";
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