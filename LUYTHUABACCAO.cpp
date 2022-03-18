#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()

using i64 = long long;

void jiangly_fan() {
	int a, b, c; std::cin >> a >> b >> c;

	auto Pow = [&](auto self, i64 a, i64 b, int MOD) -> i64 {
		if (!b) {
			return i64(1);
		}

		if (~b & 1) {
			return self(self, a * a % MOD, b / 2, MOD) % MOD;
		}
		return (a * self(self, a * a % MOD, (b - 1) / 2, MOD) % MOD) % MOD;
	};

	std::cout << Pow(Pow, i64(a), Pow(Pow, i64(b), c, 1E9 + 6), 1E9 + 7) << "\n";
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
