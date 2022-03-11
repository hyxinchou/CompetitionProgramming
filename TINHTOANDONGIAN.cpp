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
	int op1, op2, op3; std::cin >> op1 >> op2 >> op3;

	Z a = Z(op1);
	Z d = Z(op2);
	Z n = Z(op3);

	Z answer = a;

	n = n - 1;

	answer += n * a;

	answer += d * (n + 1) * n / Z(2);

	// answer += n * (n + 1) * n / Z(2);

	answer += (n - 1);

	answer += (n - 2 + 0) * (n - 2 + 1) / Z(2);

	answer += n * (n - 1 + 1) * (n - 1) / Z(2);

	answer -= (n - 1) * (n - 1 + 1) * (n - 1 + 2) / Z(3);

	std::cout << answer.val() << "\n";
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int T = 1;
	std::cin >> T;

	for (int i = 0; i < T; ++i) {
		jiangly_fan();
	}

	return 0;
}