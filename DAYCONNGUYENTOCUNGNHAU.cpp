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

const int N = 1E5 + 5;

int lpf[N], mobius[N];
std::vector<int> prime;

void sieve() {
	mobius[1] = 1;

	for (int i = 2; i < N; i++) {
		if (!lpf[i]) {
			lpf[i] = i;
			mobius[i] = -1;
			prime.push_back(i);
		}

		for (int j = 0; j < (int)prime.size() && prime[j] <= lpf[i] && prime[j] * i < N; j++) {
			lpf[prime[j] * i] = prime[j];
			mobius[prime[j] * i] = (lpf[prime[j] * i] == lpf[i] ? 0 : -mobius[i]);
		}
	}
}

void jiangly_fan() {
	int n; std::cin >> n;

	std::vector<int> A(n);
	std::vector<int> cnt(1E6, 0);

	for (auto &a : A) {
		std::cin >> a;
		++cnt[a];
	}

	std::vector<int> Gprime(1E5 + 7, 0);
	std::iota(all(Gprime), 0);

	for (int i = 2; i * i <= 1E5; ++i) {
		if (Gprime[i] == i) {
			for (int j = i * i; j <= 1E5; j += i) {
				Gprime[j] = i;
			}
		}
	}

	std::vector<int> Fcnt(1E5 + 1, 0);

	Z answer = Z(0);

	sieve();

	// std::cerr << answer.val() << "\n";

	for (int i = 1; i <= 1E5; ++i) {
		for (int j = i; j <= 1E5; j += i) Fcnt[i] += cnt[j];
		// std::cerr << i << " " << Fcnt[i] << "\n";

		// answer -= Z(pow(Z(2), Fcnt[i]) - 1);
		answer += Z(pow(Z(2), Fcnt[i]) - 1) * Z(mobius[i]);
	}

	std::cout << answer.val() << "\n";
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
