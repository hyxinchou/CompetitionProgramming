#include <bits/stdc++.h>

using i64 = long long;

int main() {

	int n, a, b; std::cin >> n >> a >> b;

	std::vector<int> loc_a, loc_b, loc;
	for (int i = 0; i < n; ++i) {
		int d, k; std::cin >> d >> k;
		loc.push_back(d);

		if (k == 1) {
			loc_a.push_back(d);
		} else {
			loc_b.push_back(d);
		}
	}

	std::sort(loc_a.begin(), loc_a.end());
	std::sort(loc_b.begin(), loc_b.end());
	std::sort(loc.begin(), loc.end());

	int l = 0, r = 1E9 + 7;

	while (r - l > 1) {
		int m = (l + r) >> 1;

		bool ok = false;

		int fi = 0, fj = 0, gi = 0, gj = 0;

		while (fi < int(loc_a.size()) && loc_a[fi] <= loc[0] + m) {
			++fi;
		}

		while (fj < int(loc_b.size()) && loc_b[fj] <= loc[0] + m) {
			++fj;
		}

		ok |= (fi - gi >= a && fj - gj >= b);

		for (int i = 1; i < n; ++i) {

			int loc_now_a = loc[i];
			int loc_now_b = loc[i] + m;

			while (gi < int(loc_a.size()) && loc_a[gi] < loc_now_a) {
				++gi;
			}

			while (gj < int(loc_b.size()) && loc_b[gj] < loc_now_a) {
				++gj;
			}

			while (fi < int(loc_a.size()) && loc_a[fi] <= loc_now_b) {
				++fi;
			}

			while (fj < int(loc_b.size()) && loc_b[fj] <= loc_now_b) {
				++fj;
			}

			ok |= (fi - gi >= a && fj - gj >= b);
		}

		if (ok) {
			// std::cout << m << "\n";
			r = m;
		} else {
			l = m;
		}
	}

	std::cout << (r >= 1E9 ? -1 : r) << "\n";

	return 0;
}
