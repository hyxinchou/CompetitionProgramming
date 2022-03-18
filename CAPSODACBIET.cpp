#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()

using i64 = long long;

void jiangly_fan() {
	std::vector<int> base;

	auto is_base = [&](int v) -> bool {
		if (v < 10) {
			return true;
		}

		int f = v % 10;

		while (v) {
			if (f ^ (v % 10)) {
				return false;
			}

			v /= 10;
		}

		return true;
	};

	for (int i = 1; i <= 2E6; ++i) {
		if (is_base(i)) {
			base.push_back(i);
		}
	}

	int n; std::cin >> n;

	std::vector<int> a(n);

	for (auto &v : a) {
		std::cin >> v;
	}

	std::sort(all(a));

	i64 answer = 0;

	for (int i = 0; i < n; ++i) {
		for (int val : base) {
			if (val >= a[i]) {
				int l = std::lower_bound(all(a), val - a[i]) - a.begin();

				if (l >= 0 && l < n && a[l] + a[i] == val) {
					int r = std::upper_bound(all(a), val - a[i]) - a.begin();
					--r;

					if (r >= 0 && r < n && a[r] + a[i] == val) {
						l = std::max(l, i + 1);

						answer += 1LL * std::max(0, r - l + 1);
					}
				}
			}
		}
	}

	std::cout << answer << "\n";
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
