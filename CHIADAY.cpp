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
	int n; std::cin >> n;

	std::vector<i64> A(n);
	for (auto &a : A) {
		std::cin >> a;
	}

	std::vector<i64> pref_sum(n + 1, 0);
	for (int i = 0; i < n; ++i) {
		pref_sum[i + 1] = pref_sum[i] + A[i];
	}

	std::vector<std::vector<Z>> dp(n + 1, std::vector<Z> (n + 1, 0));

	std::vector<std::vector<Z>> ndp(n + 1, std::vector<Z> (n + 1, 0));
	ndp[0][0] = 1;

	// dp[i][j] : go to i-th element and have j seg
	// ndp[i][j] : have i seg and have mod is j (mod = A[x] % (1 -> k))

	// sum(i -> j) % k == 0 => (pref[j] - pref[i - 1]) % k == 0 => pref[i - 1] % k == pref[j] % k

	for (int i = 0; i < n; ++i) {
		for (int k = 1; k <= i + 1; ++k) {
			dp[i + 1][k] += ndp[k - 1][pref_sum[i + 1] % k];
		}

		for (int j = 1; j <= i + 1; ++j) {
			ndp[j][pref_sum[i + 1] % (j + 1)] += dp[i + 1][j]; // have j seg and i th_element in seg j + 1
		}
	}

	Z answer = 0;
	for (int i = 1; i <= n; ++i) {
		answer += dp[n][i];
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
