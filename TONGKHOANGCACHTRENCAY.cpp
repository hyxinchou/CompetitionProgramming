#include <bits/stdc++.h>

using i64 = long long;

int main() {
	
	int n;
	std::cin >> n;
	
	std::vector<std::vector<int>> edges(n);
	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		std::cin >> u >> v;
		
		--u, --v;
		
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	
	std::vector<i64> answer(n, 0);
	std::vector<i64> siz(n, 0);
	
	auto dfs = [&](auto self, int u, int p, int d) -> void {
		answer[0] += d;
		siz[u] = 1;
		for (auto v : edges[u]) {
			if (v != p) {
				self(self, v, u, d + 1);
				siz[u] += siz[v];
			}
		}
	};
	
	auto dfs2 = [&](auto self, int u, int p) -> void {
		for (auto v : edges[u]) {
			if (v != p) {
				answer[v] = answer[u] + n - 2 * siz[v];
				self(self, v, u);
			}
		}
	};
	
	dfs(dfs, 0, -1, 0);
	dfs2(dfs2, 0, -1);
	
	for (int i = 0; i < n; ++i) {
		std::cout << answer[i] << "\n";
	}
	
	return 0;
}
