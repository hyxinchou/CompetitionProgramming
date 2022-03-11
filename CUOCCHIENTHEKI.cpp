#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()

using i64 = long long;

void jiangly_fan() {
	int n; std::cin >> n;

	int m1 = n / 2;
	int m2 = n - m1;

	std::vector<i64> A1(m1), A2(m2);
	for (auto &a : A1) {
		std::cin >> a;
	}
	for (auto &a : A2) {
		std::cin >> a;
	}

	i64 Sum = std::accumulate(all(A1), i64(0)) + std::accumulate(all(A2), i64(0));
	i64 half_Sum = Sum / 2;

	// std::map<i64, int> mp2;
	std::vector<i64> F, G;

	for (int mask = 0; mask < (1 << m1); ++mask) {
		i64 sum = 0;

		for (int i = 0; i < m1; ++i) {
			if (mask >> i & 1) {
				sum += A1[i];
			}
		}

		F.push_back(sum);
		G.push_back(sum);
	}

	std::sort(all(F));
	std::sort(all(G));

	G.erase(std::unique(all(G)), G.end());

	i64 Min_diff = 1E18;

	for (int mask = 0; mask < (1 << m2); ++mask) {
		i64 sum = 0;

		for (int i = 0; i < m2; ++i) {
			if (mask >> i & 1) {
				sum += A2[i];
			}
		}

		// ++mp2[sum];

		int itr = std::lower_bound(all(G), half_Sum - sum) - G.begin();

		i64 diff1 = 1E18, diff2 = 1E18;

		if (itr >= 0 && itr < int(G.size())) {
			diff1 = std::abs(G[itr] + sum - (Sum - G[itr] - sum));
		}

		--itr;

		if (itr >= 0 && itr < int(G.size())) {
			diff2 = std::abs(G[itr] + sum - (Sum - G[itr] - sum));
		}

		Min_diff = std::min(Min_diff, std::min(diff1, diff2));
	}

	i64 way = 0;

	i64 value = (Sum - Min_diff) / 2 + Min_diff;

	for (int mask = 0; mask < (1 << m2); ++mask) {
		i64 sum = 0;

		for (int i = 0; i < m2; ++i) {
			if (mask >> i & 1) {
				sum += A2[i];
			}
		}

		if (sum <= value) {
			int l = std::lower_bound(all(F), value - sum) - F.begin();

			if (l >= 0 && l < int(F.size()) && F[l] + sum == value) {
				int r = std::upper_bound(all(F), value - sum) - F.begin();
				--r;

				way += r - l + 1;
			}
		}
	}

	if (!Min_diff) {
		way /= 2;
	}

	std::cout << Min_diff << " " << way << "\n";
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