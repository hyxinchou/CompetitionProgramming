#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()

using i64 = long long;

void jiangly_fan() {
	int n, k, r, p; std::cin >> n >> k >> r >> p;

	std::vector<std::vector<i64>> A(n, std::vector<i64> (n, 0));
	for (auto &a : A) {
		for (auto &b : a) {
			std::cin >> b;
		}
	}

	std::vector<std::vector<i64>> pref(n + 1, std::vector<i64> (n + 1, 0));
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			pref[i][j] = pref[i][j - 1] + A[i - 1][j - 1];
		}
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			pref[j][i] += pref[j - 1][i];
		}
	}

	// for (int i = 0; i <= n; ++i) {
	// 	for (int j = 0; j <= n; ++j) {
	// 		std::cerr << pref[i][j] << " \n"[j == n];
	// 	}
	// }

	i64 answer = 0;

	while (k--) {
		i64 res = 0;

		for (int i = 0; i < p; ++i) {
			int x, y; std::cin >> x >> y;
			--x, --y;

			res += pref[x + r][y + r] - pref[x][y + r] - pref[x + r][y] + pref[x][y];
		}

		answer = std::max(answer, res);
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