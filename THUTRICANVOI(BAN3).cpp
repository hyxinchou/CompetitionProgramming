#include <bits/stdc++.h>

template <class F> struct y_combinator {
	F f;
	template <class... Args>
	decltype(auto) operator()(Args&&... args) const {
		return f(*this, std::forward<Args>(args)...);
	}
};
template <class F> y_combinator<std::decay_t<F>> make_y_combinator(F&& f) {
	return {std::forward<F>(f)};
}

int main() {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n, m; std::cin >> n >> m;
	std::vector<int> w(n);
	for (auto &v : w) std::cin >> v;
	int lhs = n / 2;
	int rhs = n - lhs;
	std::vector<int> left_array, right_array;
	for (int i = 0; i < lhs; ++i) left_array.push_back(w[i]);
	for (int i = lhs; i < n; ++i) right_array.push_back(w[i]);
	std::vector<int> f(7E6, 0);
	int base = 4E6;
	int64_t answer = 0;
	auto rec = make_y_combinator([&](auto && rec, int Time, int add1, int add2, int add3) -> void {
		if (Time >= lhs) {
			++f[add1 - add2 + base];
			return;
		}
		rec(Time + 1, add1 + left_array[Time], add2, add3);
		rec(Time + 1, add1, add2 + left_array[Time], add3);
		rec(Time + 1, add1, add2, add3 + left_array[Time]);
	});
	auto rec2 = make_y_combinator([&](auto && rec2, int Time, int add1, int add2, int add3) -> void {
		if (Time >= rhs) {
			answer += 1LL * f[m + add1 - add2 + base];
			return;
		}
		rec2(Time + 1, add1 + right_array[Time], add2, add3);
		rec2(Time + 1, add1, add2 + right_array[Time], add3);
		rec2(Time + 1, add1, add2, add3 + right_array[Time]);
	});
	rec(0, 0, 0, 0);
	rec2(0, 0, 0, 0);
	if (answer) std::cout << "YES\n" << 2 * answer << "\n";
	else std::cout << "NO\n";

	return 0;
}
