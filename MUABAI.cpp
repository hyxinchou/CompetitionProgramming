#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()

using i64 = long long;

void jiangly_fan() {
	i64 C, p, n1, n2, t1, t2; std::cin >> C >> p >> n1 >> n2 >> t1 >> t2;

	i64 l = 0, r = 1E17;

	while (r - l > 1) {
		i64 m = (l + r) / 2;

		i64 cost = m / n1 * t1 + m / n2 * t2 + m * p;

		if (cost <= C) {
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
	std::cin >> T;

	for (int i = 0; i < T; ++i) {
		// std::cout << "Case " << i + 1 << ": ";
		jiangly_fan();
	}

	return 0;
}