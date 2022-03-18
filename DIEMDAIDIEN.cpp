#include <bits/stdc++.h>

using i64 = long long;

int main() {

	int n; std::cin >> n;

	std::vector<std::pair<i64, i64>> seg;
	for (int i = 0; i < n; ++i) {
		i64 x, l; std::cin >> x >> l;

		seg.push_back(std::make_pair(x, x + l));
	}

	std::sort(seg.begin(), seg.end());

	// for (auto [l, r] : seg) {
	// 	std::cerr << l << " " << r << "\n";
	// }

	i64 l = 0, r = 1E16;

	while (r - l > 1) {
		i64 m = (l + r) / 2;

		i64 last = seg[0].first;
		bool not_ok = false;

		for (int i = 1; i < n; ++i) {
			last = std::max(seg[i].first, last + m);

			not_ok |= !(last >= seg[i].first && last <= seg[i].second);
		}

		// std::cerr << m << " " << not_ok << "\n";

		if (!not_ok) {
			l = m;
		} else {
			r = m;
		}
	}

	std::cout << l << "\n";

	return 0;
}
