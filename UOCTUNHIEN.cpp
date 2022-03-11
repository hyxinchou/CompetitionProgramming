#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()

using i64 = long long;

void jiangly_fan() {

}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int T = 1;
	std::cin >> T;

	std::vector<i64> sum_of(1000007);
	std::iota(all(sum_of), 0);
	std::vector<int> cnt_of(1000007, 1);

	for (int i = 2; i <= 1000000; ++i) {
		++sum_of[i];
		++cnt_of[i];
	}

	// for (int i = 1; i <= 10; ++i) {
	// 	std::cout << i << " " << cnt_of[i] << " " << sum_of[i] << "\n";
	// }

	for (int i = 2; i * i <= 1000000; ++i) {
		for (int j = i * i; j <= 1000000; j += i) {
			cnt_of[j] += (1 + (j / i != i ? 1 : 0));
			sum_of[j] += i + (j / i != i ? j / i : 0);
		}
	}

	std::vector<i64> pref_sum(1000007, 0);

	for (int i = 1; i <= 1000000; ++i) {
		pref_sum[i] = pref_sum[i - 1] + sum_of[i];
	}

	std::vector<int> pref_count(1000007, 0);

	for (int i = 1; i <= 1000000; ++i) {
		pref_count[i] = pref_count[i - 1] + cnt_of[i];
	}

	// for (int i = 1; i <= 10; ++i) {
	// 	std::cout << i << " " << cnt_of[i] << " " << sum_of[i] << "\n";
	// }

	for (int i = 0; i < T; ++i) {
		// jiangly_fan();
		int x, y; std::cin >> x >> y;

		std::cout << pref_count[y] - pref_count[x - 1] << " " << pref_sum[y] - pref_sum[x - 1] << "\n";
	}

	return 0;
}