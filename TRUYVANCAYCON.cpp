#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()

using i64 = long long;

void jiangly_fan() {
	int N, Q; std::cin >> N >> Q;

	std::vector<i64> v(N);
	for (auto &a : v) {
		std::cin >> a;
	}

	std::vector<std::vector<int>> edges(N);
	for (int i = 0; i < N - 1; ++i) {
		int u, v; std::cin >> u >> v;
		--u, --v;

		edges[u].push_back(v);
		edges[v].push_back(u);
	}

	int Time = 0;
	std::vector<int> IN(N, -1), OUT(N, -1);

	auto dfs = [&](auto self, int u, int p) -> void {
		IN[u] = Time++;

		for (auto v : edges[u]) {
			if (v != p) {
				self(self, v, u);
			}
		}

		OUT[u] = Time++;
	};
	dfs(dfs, 0, -1);

	int n = Time + 1;

	// std::cerr << n << "\n";

	std::vector<i64> a(n + 1, 0);

	auto add = [&](int x, i64 V) -> void {
		for (int i = x + 1; i <= n; i += i & -i) {
			a[i - 1] += V;
		}
	};

	auto sum = [&](int x) -> i64 {
		i64 answer = 0;
		for (int i = x; i; i -= i & -i) {
			answer += a[i - 1];
		}
		return answer;
	};

	for (int i = 0; i < N; ++i) {
		add(IN[i], v[i]);

		// std::cout << IN[i] << " " << v[i] << "\n";
	}

	while (Q--) {
		int op; std::cin >> op;

		if (op == 1) {
			i64 x;
			int u; std::cin >> u >> x;
			--u;

			add(IN[u], x - v[u]);

			// std::cout << u << " " << x - v[u] << "\n";

			v[u] = x;
		} else {
			int u; std::cin >> u;
			--u;

			// std::cout << IN[u] << " " << OUT[u] << "\n";
			// std::cout << sum(OUT[u]) << " " << sum(IN[u] - 1) << "\n";
			std::cout << sum(OUT[u]) - sum(IN[u]) << "\n";
		}
	}
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
