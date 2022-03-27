#pragma GCC optimize("O2")
#include <bits/stdc++.h>

int main() {

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

	int n;
	int64_t m; std::cin >> n >> m;
	std::vector<int64_t> w(n);
	for (auto &v : w) std::cin >> v;
	int lhs = n / 2;
	int rhs = n - lhs;
	std::vector<int64_t> left_array, right_array;
	for (int i = 0; i < lhs; ++i) left_array.push_back(w[i]);
	for (int i = lhs; i < n; ++i) right_array.push_back(w[i]);
	auto Pow = [&](auto self, int a, int b) -> int {
		if (!b) return 1;
		if (~b & 1) return self(self, a * a, b >> 1);
		return a * self(self, a * a, (b - 1) >> 1);
	};
	std::unordered_map<int64_t, int64_t> f;
	for (int mask = 0; mask < Pow(Pow, 3, lhs); ++mask) {
		std::vector<int64_t> add(3, 0);
		int ret = mask;
		for (int id = 0; id < lhs; ++id) {
			add[ret % 3] += left_array[id];
			ret /= 3;
		}
		++f[add[0] - add[1]];
	}
	int64_t answer = 0;
	for (int mask = 0; mask < Pow(Pow, 3, rhs); ++mask) {
		std::vector<int64_t> add(3, 0);
		int ret = mask;
		for (int id = 0; id < rhs; ++id) {
			add[ret % 3] += right_array[id];
			ret /= 3;
		}
		answer += f[m + add[0] - add[1]];
	}
  if (answer) std::cout << "YES\n" << 2 * answer << "\n";
  else std::cout << "NO\n";

	return 0;
}
