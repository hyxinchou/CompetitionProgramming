#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()

using i64 = long long;

void jiangly_fan() {
	i64 k;
	int n; std::cin >> n >> k;

	std::map<i64, i64> l, r;
	std::vector<i64> A(n);

	for (auto &a : A) {
		std::cin >> a;

		++r[a];
	}

	--r[A[0]];
	--r[A[1]];
	++l[A[0]];

	i64 answer = 0;

	for (int i = 1; i < n - 1; ++i) {
		if (A[i] % k == 0) {
			answer += l[A[i] / k] * r[A[i] * k];
		}
		++l[A[i]];
		--r[A[i + 1]];
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
