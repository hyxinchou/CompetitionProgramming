#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()

using i64 = long long;

void jiangly_fan() {
	int n, m; std::cin >> n >> m;

	const i64 INF = 1E16;

	std::vector<std::vector<i64>> edges(n, std::vector<i64> (n, INF));
	for (int i = 0; i < n; ++i) {
		edges[i][i] = 0;
	}

	for (int i = 0; i < m; ++i) {
		i64 t;
		int a, b; std::cin >> a >> b >> t;
		--a, --b;

		edges[a][b] = std::min(edges[a][b], t);
	}

	// for (int i = 0; i < n; ++i) {
	// 	for (int j = 0; j < n; ++j) {
	// 		std::cerr << edges[i][j] << " \n"[j == n - 1];
	// 	}
	// }

	std::cerr << "\n";

	int k, q; std::cin >> k >> q;

	k = std::min(k, 75);

	// std::cerr << k << " " << n << "\n";

	auto dijkstra = [&](int S) -> std::vector<i64> {
		std::vector<std::vector<i64>> d(n, std::vector<i64> (k + 7, INF));
		std::priority_queue<std::array<i64, 3>, std::vector<std::array<i64, 3>>, std::greater<>> pq;
		// std::vector<i64> change_of(n, INF);

		pq.push({0, S, 0});
		d[S][0] = 0;
		// change_of[S] = 0;

		while (pq.size()) {
			auto [du, u, bus] = pq.top();
			pq.pop();

			if (d[u][bus] != du) {
				continue;
			}

			for (int v = 0; v < n; ++v) {
				if (bus + 1 <= k && edges[u][v] != INF && edges[u][v]) {
					int dv = edges[u][v];
					if (d[v][bus + 1] > d[u][bus] + dv) {
						d[v][bus + 1] = d[u][bus] + dv;

						// change_of[v] = bus + 1;

						pq.push({d[v][bus + 1], v, bus + 1});
					}
				}
			}
		}

		// for (int i = 0; i < n; ++i) {
		// 	std::cerr << change_of[i] << " \n"[i == n - 1];
		// }

		std::vector<i64> answer(n, INF);
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j <= k; ++j) {
				answer[i] = std::min(answer[i], d[i][j]);
			}
			answer[i] = (answer[i] == INF ? -1 : answer[i]);
		}

		return answer;
	};

	std::map<int, std::vector<i64>> answer;

	// dijkstra(0);

	for (int i = 0; i < n; ++i) {
		answer[i] = dijkstra(i);

		// for (int j = 0; j < n; ++j) {
		// 	std::cerr << answer[i][j] << " \n"[j == n - 1];
		// }
	}

	while (q--) {
		int c, d; std::cin >> c >> d;
		--c, --d;

		std::cout << answer[c][d] << "\n";
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