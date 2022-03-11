#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()

using i64 = long long;

void jiangly_fan() {
	i64 N; std::cin >> N;

	std::vector<int> C(100, 0);

	int mx = 0;

	for (i64 i = 2; i * i <= N; ++i) {
		if (N % i == 0) {
			int ret = 0;
			i64 cop = N;
			while (cop % i == 0) {
				cop /= i;
				++ret;
			}
			++C[ret];
			mx = std::max(mx, ret);
		}
	}

	i64 answer = C[mx];
	i64 add = 1;
	for (int i = 2; i < 100; ++i) {
		if (C[i]) {
			if (i ^ mx) {
				add *= C[i];
			}
		}
	}
	// std::cerr << add << "\n";
	std::cout << answer * add << "\n";
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