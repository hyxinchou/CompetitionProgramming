#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()

using i64 = long long;

void jiangly_fan() {
	i64 n, m; std::cin >> n >> m;

	std::vector<i64> divisor;

	i64 cop = m;

	std::map<i64, i64> mp;

	for (i64 i = 2; i <= std::sqrt(cop); ++i) {
		if (m % i == 0) {
			divisor.push_back(i);
			while (m && m % i == 0) {
				m /= i;
				++mp[i];
			}
		}
	}

	if (m > 1) {
		divisor.push_back(m);
		++mp[m];
	}

	std::sort(all(divisor));
	divisor.erase(std::unique(all(divisor)), divisor.end());

	auto Legendre = [&](i64 num, i64 p) -> i64 {
		i64 answer = 0;

		while (num) {
			num /= p;
			answer += num;
		}

		return answer;
	};

	i64 answer = 1E16;

	for (auto val : divisor) {
		// std::cerr << val << "\n";

		i64 ret = Legendre(n, val);

		answer = std::min(answer, ret / mp[val]);
	}

	if (!answer) {
		answer = -1;
	}

	std::cout << answer << "\n";
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