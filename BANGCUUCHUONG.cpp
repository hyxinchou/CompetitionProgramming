#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()

using i64 = long long;

void jiangly_fan() {
	i64 n; std::cin >> n;

	i64 mhs = n * n / 2 + 1;

	i64 l = 1, r = 1E12 + 7;

	while (r - l > 1) {
		i64 m = (l + r) / 2;

		i64 idx = 0;

		for (int i = 1; i <= n; ++i) {
			idx += std::min(n, (m - 1) / i);
		}

		if (idx < mhs) {
			l = m;
		} else {
			r = m;
		}
	}

	std::cout << l << "\n";
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