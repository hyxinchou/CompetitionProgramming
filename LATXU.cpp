#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()

using i64 = long long;

std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());

void jiangly_fan() {
	int n, m; std::cin >> n >> m;

	const i64 MOD = 1E18;

	std::vector<i64> G(n);
	for (int i = 0; i < n; ++i) {
		G[i] = rng() % MOD;
	}

	i64 base = 0;

	for (int i = 0; i < n; ++i) {
		int val; std::cin >> val;

		if (!val) {
			base ^= G[i];
		}
	}

	std::vector<i64> change(m, 0);

	for (int i = 0; i < m; ++i) {
		int len; std::cin >> len;

		for (int j = 0; j < len; ++j) {
			int val; std::cin >> val;
			--val;

			change[i] ^= G[val];
		}
	}

	// std::vector<bool> on(m, false);

	int mid = m / 2;

	std::map<i64, bool> mp;
	std::map<i64, int> mp2;

	for (int mask = 0; mask < (1 << mid); ++mask) {
		i64 Fbase = 0;

		for (int i = 0; i < mid; ++i) {
			if (mask >> i & 1) {
				Fbase ^= change[i];
			}
		}

		mp[Fbase] = true;
		mp2[Fbase] = mask;
	}

	int Fmid = m - mid;

	for (int mask = 0; mask < (1 << Fmid); ++mask) {
		i64 Fbase = 0;

		for (int i = 0; i < Fmid; ++i) {
			if (mask >> i & 1) {
				Fbase ^= change[i + mid];
			}
		}

		if (mp[base ^ Fbase]) {
			std::cout << __builtin_popcount(mp2[base ^ Fbase]) + __builtin_popcount(mask) << "\n";

			for (int i = 0; i < 30; ++i) {
				if (mp2[base ^ Fbase] >> i & 1) {
					std::cout << i + 1 << " ";
				}
			}

			for (int i = 0; i < 30; ++i) {
				if (mask >> i & 1) {
					std::cout << i + 1 + mid << " ";
				}
			}
			break;
		}
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