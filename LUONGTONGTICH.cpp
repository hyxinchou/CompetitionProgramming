#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()

using i64 = long long;

constexpr int P = 1000000007;

// assume -P <= x < 2P
int norm(int x) {
	if (x < 0) {
		x += P;
	}
	if (x >= P) {
		x -= P;
	}
	return x;
}
template<class T>
T power(T a, int b) {
	T res = 1;
	for (; b; b /= 2, a *= a) {
		if (b % 2) {
			res *= a;
		}
	}
	return res;
}
struct Z {
	int x;
	Z(int x = 0) : x(norm(x)) {}
	int val() const {
		return x;
	}
	Z operator-() const {
		return Z(norm(P - x));
	}
	Z inv() const {
		assert(x != 0);
		return power(*this, P - 2);
	}
	Z &operator*=(const Z &rhs) {
		x = i64(x) * rhs.x % P;
		return *this;
	}
	Z &operator+=(const Z &rhs) {
		x = norm(x + rhs.x);
		return *this;
	}
	Z &operator-=(const Z &rhs) {
		x = norm(x - rhs.x);
		return *this;
	}
	Z &operator/=(const Z &rhs) {
		return *this *= rhs.inv();
	}
	friend Z operator*(const Z &lhs, const Z &rhs) {
		Z res = lhs;
		res *= rhs;
		return res;
	}
	friend Z operator+(const Z &lhs, const Z &rhs) {
		Z res = lhs;
		res += rhs;
		return res;
	}
	friend Z operator-(const Z &lhs, const Z &rhs) {
		Z res = lhs;
		res -= rhs;
		return res;
	}
	friend Z operator/(const Z &lhs, const Z &rhs) {
		Z res = lhs;
		res /= rhs;
		return res;
	}
};

template <typename T> T pow(T a, long long b) {
	assert(b >= 0);
	T r = 1; while (b) { if (b & 1) r *= a; b >>= 1; a *= a; } return r;
}


void jiangly_fan() {
	int n; std::cin >> n;

	std::vector<i64> x(n), k(n);

	for (int i = 0; i < n; ++i) {
		std::cin >> x[i] >> k[i];
	}

	Z sum = 1;

	for (int i = 0; i < n; ++i) {
		sum *= Z(pow(Z(x[i]), k[i] + 1) - 1) / Z(x[i] - 1);
	}

	Z product = 1;

	// N ^ (x / 2) = (a1 ^ x1 * a2 ^ x2 * ...) ^ (x / 2) = a1 ^ (x1 * x / 2) * a2 ^ (x2 * x / 2) * ...(1)
	// but x = (x1 + 1) * (x2 + 1) * .... => (1) = a1 ^ (x1 * (x1 + 1) * (x2 + 1) * .. / 2) * ...
	// ai = ai ^ (xi * (xi + 1) / 2) * ((x1 + 1) * (x2 + 1) * ...) = ai ^ (xi * (xi + 1) / 2) * pref_mod
	// (ai ^ (x1 + 1) * (x2 + 1) * ...) % MOD == ai ^ ((x1 + 1) * (x2 + 1) * ... % (MOD - 1)) = ai ^ pref_mod (Fermat's little)

	i64 pref_mod = 1;

	Z cnt_divisor = 1;

	for (int i = 0; i < n; ++i) {
		product = pow(Z(product), k[i] + 1) * pow(pow(Z(x[i]), k[i] * (k[i] + 1) / 2), pref_mod);

		pref_mod = pref_mod * (k[i] + 1) % (P - 1);

		cnt_divisor *= (k[i] + 1);
	}

	std::cout << cnt_divisor.val() << " " << sum.val() << " " << product.val() << "\n";
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