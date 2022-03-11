#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()

using i64 = long long;

void jiangly_fan() {
	int n, m; std::cin >> n >> m;

	std::vector<std::vector<std::pair<i64, int>>> edges(n);

	for (int i = 0; i < m; ++i) {
		i64 c;
		int a, b; std::cin >> a >> b >> c;
		--a, --b;

		edges[a].push_back(std::make_pair(c, b));
		// edges[b].push_back(std::make_pair(c, a));
	}

	std::vector<i64> d(n, -1);
	std::priority_queue < std::pair<i64, int>, std::vector<std::pair<i64, int>>, std::greater<>> pq;

	pq.push(std::make_pair(0, 0));

	while (pq.size()) {
		auto [du, u] = pq.top();
		pq.pop();

		if (d[u] == -1) {
			d[u] = du;

			for (auto [dv, v] : edges[u]) {
				if (d[v] == -1) {
					pq.push(std::make_pair(d[u] + dv, v));
				}
			}
		}
	}

	for (int i = 0; i < n; ++i) {
		std::cout << d[i] << " \n"[i == n - 1];
	}
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