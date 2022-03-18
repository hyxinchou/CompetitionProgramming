#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()

using i64 = long long;

struct Flow {
    static constexpr int INF = 1e9;
    int n;
    struct Edge {
        int to, cap;
        Edge(int to, int cap) : to(to), cap(cap) {}
    };
    std::vector<Edge> e;
    std::vector<std::vector<int>> g;
    std::vector<int> cur, h;
    Flow(int n) : n(n), g(n) {}
    bool bfs(int s, int t) {
        h.assign(n, -1);
        std::queue<int> que;
        h[s] = 0;
        que.push(s);
        while (!que.empty()) {
            int u = que.front();
            que.pop();
            for (int i : g[u]) {
                int v = e[i].to;
                int c = e[i].cap;
                if (c > 0 && h[v] == -1) {
                    h[v] = h[u] + 1;
                    if (v == t)
                        return true;
                    que.push(v);
                }
            }
        }
        return false;
    }
    int dfs(int u, int t, int f) {
        if (u == t)
            return f;
        int r = f;
        for (int &i = cur[u]; i < int(g[u].size()); ++i) {
            int j = g[u][i];
            int v = e[j].to;
            int c = e[j].cap;
            if (c > 0 && h[v] == h[u] + 1) {
                int a = dfs(v, t, std::min(r, c));
                e[j].cap -= a;
                e[j ^ 1].cap += a;
                r -= a;
                if (r == 0)
                    return f;
            }
        }
        return f - r;
    }
    void addEdge(int u, int v, int c) {
        g[u].push_back(e.size());
        e.emplace_back(v, c);
        g[v].push_back(e.size());
        e.emplace_back(u, 0);
    }
    int maxFlow(int s, int t) {
        int ans = 0;
        while (bfs(s, t)) {
            cur.assign(n, 0);
            ans += dfs(s, t, INF);
        }
        return ans;
    }
};

void jiangly_fan() {
	int N, M; std::cin >> N >> M;

	std::vector<std::string> A(N);
	for (auto &a : A) {
		std::cin >> a;
	}

	auto get = [&](int x, int y) -> int {
		return x * M + y;
	};

	Flow flow(2 * N * M + 1);

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (A[i][j] != '.') {
				flow.addEdge(get(i, j), get(i, j) + N * M, 1);
			}
		}
	}

	constexpr int INF = 1E9;

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (A[i][j] != '.') {
				for (int k = i + 1; k < N; ++k) {
					if (A[k][j] != '.') {
						flow.addEdge(get(i, j) + N * M, get(k, j), INF);
						flow.addEdge(get(k, j) + N * M, get(i, j), INF);
					}
				}

				for (int k = j + 1; k < M; ++k) {
					if (A[i][k] != '.') {
						flow.addEdge(get(i, j) + N * M, get(i, k), INF);
						flow.addEdge(get(i, k) + N * M, get(i, j), INF);
					}
				}
			}
		}
	}

	std::pair<int, int> S, E;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (A[i][j] == 'S') {
				S = std::make_pair(i, j);
			}

			if (A[i][j] == 'T') {
				E = std::make_pair(i, j);
			}
		}
	}

	auto [x, y] = S;
	auto [u, v] = E;

	int ans = flow.maxFlow(get(x, y) + N * M, get(u, v));

	std::cout << (ans >= INF ? -1 : ans) << "\n";
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
