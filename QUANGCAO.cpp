#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()

using i64 = long long;

void jiangly_fan() {
	int N, M; std::cin >> N >> M;

	std::vector<std::vector<int>> edges(N);
	for (int i = 0; i < M; ++i) {
		int u, v; std::cin >> u >> v;
		--u, --v;

		edges[u].push_back(v);
		edges[v].push_back(u);
	}

	std::vector<bool> vis(N, false);

	auto dfs = [&](auto self, int u) -> void {
		for (auto v : edges[u]) {
			if (!vis[v]) {
				vis[v] = true;

				self(self, v);
			}
		}
	};

	int comp = 0;

	for (int i = 0; i < N; ++i) {
		if (!vis[i]) {
			vis[i] = true;

			dfs(dfs, i);

			++comp;
		}
	}

	std::cout << M - N + comp << "\n";
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
