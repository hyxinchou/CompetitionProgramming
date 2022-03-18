#include <bits/stdc++.h>

using i64 = long long;

int main() {

	int N; std::cin >> N;

	std::vector<int> pref_zero(N + 1, 0), pref_one(N + 1, 0);
	for (int i = 0; i < N; ++i) {
		int a; std::cin >> a;

		pref_zero[i + 1] = pref_zero[i] + (1 - a);
		pref_one[i + 1] = pref_one[i] + a;
	}

	std::vector<int> loc(2 * N + 2, -2);
	loc[N + 1] = -1;

	int cnt_zero = 0, cnt_one = 0;

	int answer = 0;

	for (int i = 0; i < N; ++i) {
		cnt_zero = pref_zero[i + 1];
		cnt_one = pref_one[i + 1];

		int diff = cnt_zero - cnt_one + (N + 1);
		if (loc[diff] != -2) {
			// std::cerr << answer << " " << cnt_zero << " " << cnt_one << " " << loc[diff] << " ";
			answer = std::max(answer, i - loc[diff]);
			// std::cerr << answer << "\n";
		} else {
			loc[diff] = i;
		}
	}

	std::cout << answer << "\n";

	return 0;
}
