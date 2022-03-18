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

void jiangly_fan() {

}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int T = 1;
	std::cin >> T;

	std::vector<Z> fac(1E6 + 7, 0), invfac(1E6 + 7, 0);
	fac[0] = 1;
	for (int i = 1; i <= 1E6; ++i) {
		fac[i] = fac[i - 1] * Z(i);
	}
	invfac[1E6] = fac[1E6].inv();
	for (int i = 1E6; i; --i) {
		invfac[i - 1] = invfac[i] * Z(i);
	}

	auto nCr = [&](int N, int R) -> Z {
		if (N < R) {
			return Z(0);
		}

		return fac[N] * invfac[N - R] * invfac[R];
	};

	for (int i = 0; i < T; ++i) {
		// std::cout << "Case " << i + 1 << ": ";
		// jiangly_fan();
		int k, n; std::cin >> n >> k;

		std::cout << nCr(n, k).val() << "\n";
	}

	return 0;
}
