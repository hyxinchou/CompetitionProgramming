#include <bits/stdc++.h>

using i64 = long long;

int main() {

	int n; std::cin >> n;

	std::vector<std::vector<int>> A(n, std::vector<int> (n));
	for (auto &a : A) {
		for (auto &b : a) {
			std::cin >> b;
		}
	}

	int l = -1, r = 300;

	while (r - l > 1) {
		int m = (l + r) >> 1;

		bool ok = false;

		std::vector<std::vector<bool>> vis(n, std::vector<bool> (n, false));

		auto dfs = [&](auto self, int u, int v, int lhs, int rhs) -> void {
			vis[u][v] = true;

			for (int i = -1; i <= 1; ++i) {
				for (int j = -1; j <= 1; ++j) {
					if (std::abs(i + j) == 1) {
						int nx = u + i;
						int ny = v + j;

						if (nx >= 0 && ny >= 0 && nx < n && ny < n && !vis[nx][ny] && A[nx][ny] >= lhs && A[nx][ny] <= rhs) {
							self(self, nx, ny, lhs, rhs);
						}
					}
				}
			}
		};

		for (int i = 0; i <= 110; ++i) {
			for (int j = 0; j < n; ++j) {
				std::fill(vis[j].begin(), vis[j].end(), false);
			}
			if (A[0][0] >= i && A[0][0] <= i + m) {
				dfs(dfs, 0, 0, i, i + m);
			}

			ok |= vis[n - 1][n - 1];
		}

		if (ok) {
			r = m;
		} else {
			l = m;
		}
	}

	std::cout << r << "\n";

	return 0;
}
