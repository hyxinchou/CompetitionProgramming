// #pragma GCC optimize("O2")
// #pragma GCC target("avx")
#include <bits/stdc++.h>

using i64 = long long;

int main() {

	std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr);

	int n, m, k; std::cin >> n >> m >> k;

	std::vector<std::vector<i64>> A(n + 1, std::vector<i64> (m + 1));
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			std::cin >> A[i][j];
		}
	}

	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			A[i][j] += A[i][j - 1];
		}
	}

	for (int i = 1; i <= m; ++i) {
		for (int j = 1; j <= n; ++j) {
			A[j][i] += A[j - 1][i];
		}
	}

	auto getSum = [&](int x, int y, int u, int v) -> i64 {
		return A[u][v] - A[x - 1][v] - A[u][y - 1] + A[x - 1][y - 1];
	};

	while (k--) {
		int x, y, u, v; std::cin >> x >> y >> u >> v;

		auto calc = [&]() -> i64 {
			int l = x - 1, r = u;

			i64 answer = 1E18;

			while (r - l > 1) {
				int m = (l + r) >> 1;

				// i64 res = 1E18;

				i64 left = getSum(x, y, m , v);
				i64 right = getSum(m + 1, y, u, v);
				// res = std::max(left, right);

				if (left <= right) {
					// answer = res;
					l = m;
				} else {
					r = m;
				}
			}

			i64 f = getSum(x, y, l, v);
			i64 g = getSum(l + 1, y, u, v);

			answer = std::min(answer, g - f);

			l = x - 1, r = u;

			while (r - l > 1) {
				int m = (l + r) >> 1;

				// i64 res = 1E18;

				i64 left = getSum(x, y, m , v);
				i64 right = getSum(m + 1, y, u, v);
				// res = std::max(left, right);

				if (left >= right) {
					// answer = res;
					r = m;
				} else {
					l = m;
				}
			}

			f = getSum(x, y, r, v);
			g = getSum(r + 1, y, u, v);

			answer = std::min(answer, f - g);

			return answer;
		};

		auto calc2 = [&]() -> i64 {
			int l = y - 1, r = v;

			i64 answer = 1E18;

			while (r - l > 1) {
				int m = (l + r) >> 1;

				// i64 res = 1E18;

				i64 left = getSum(x, y, u , m);
				i64 right = getSum(x, m + 1, u, v);
				// res = std::max(left, right);

				if (left <= right) {
					l = m;
				} else {
					r = m;
				}
			}

			i64 f = getSum(x, y, u, l);
			i64 g = getSum(x, l + 1, u, v);

			answer = std::min(answer, g - f);

			l = y - 1, r = v;

			while (r - l > 1) {
				int m = (l + r) >> 1;

				// i64 res = 1E18;

				i64 left = getSum(x, y, u , m);
				i64 right = getSum(x, m + 1, u, v);
				// res = std::max(left, right);

				if (left >= right) {
					r = m;
				} else {
					l = m;
				}
			}

			f = getSum(x, y, u, r);
			g = getSum(x, r + 1, u, v);

			answer = std::min(answer, f - g);

			return answer;
		};

		i64 f = std::min(calc(), calc2());

		std::cout << f << "\n";
		// std::cout << f - (getSum(x, y, u, v) - f) << "\n";
	}

	return 0;
}
