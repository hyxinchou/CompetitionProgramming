// #pragma GCC optimize("O2")
#include <bits/stdc++.h>
using i64 = long long;
int main() {

	constexpr int nxm = 1E4;
	std::vector<int> lp(nxm + 1);
	std::vector<int> pr;

	for (int i = 2; i <= nxm; ++i) {
		if (!lp[i]) {
			lp[i] = i;
			pr.push_back(i);
		}

		for (int j = 0; j < int(pr.size()) && pr[j] <= lp[i] && i * pr[j] <= nxm; ++j) {
			lp[i * pr[j]] = pr[j];
		}
	}

	auto count_divisor = [&](int n) -> i64 {
		i64 answer = 1;

		for (int i = 0; i < int(pr.size()) && pr[i] <= n; ++i) {
			if (n % pr[i] == 0) {
				int res = 0;

				while (n && n % pr[i] == 0) {
					n  /= pr[i];
					++res;
				}

				answer *= 1LL * (res + 1);
			}
		}

		if (n > 1) {
			answer *= 2;
		}

		return answer;
	};

	i64 answer = 0;

	int n; std::cin >> n;
	for (int i = 0; i < n; ++i) {
		int a; std::cin >> a;

		answer += a * count_divisor(a);
	}

	std::cout << answer << "\n";

	return 0;
}
