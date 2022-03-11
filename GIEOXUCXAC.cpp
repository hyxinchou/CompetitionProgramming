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
    i64 M;
    int N; std::cin >> N >> M;

    std::vector<int> cnt(7, 0);

    for (int i = 2; i < 6; ++i) {
        if (M && M % i == 0) {
            while (M && M % i == 0) {
                M /= i;
                ++cnt[i];
            }
        }
    }

    if (M > 1) {
        std::cout << "0\n";
        return 0;
    }

    std::vector<std::vector<std::vector<std::vector<Z>>>> dp(107, std::vector<std::vector<std::vector<Z>>> (70, std::vector<std::vector<Z>> (50, std::vector<Z> (30, 0))));
    dp[0][0][0][0] = 1;

    // O(N * 7 * 70 * 50 * 30)

    for (int i = 0; i < N; ++i) {
        // for (int j = 1; j < 7; ++j) {
        for (int _ = 0; _ <= cnt[2]; ++_) {
            for (int __ = 0; __ <= cnt[3]; ++__) {
                for (int ___ = 0; ___ <= cnt[5]; ++___) {
                    if (dp[i][_][__][___].val()) {
                        // if (j == 1) {
                        dp[i + 1][_][__][___] += dp[i][_][__][___];
                        // } else if (j == 2) {
                        dp[i + 1][_ + 1][__][___] += dp[i][_][__][___];
                        // } else if (j == 3) {
                        dp[i + 1][_][__ + 1][___] += dp[i][_][__][___];
                        // } else if (j == 4) {
                        dp[i + 1][_ + 2][__][___] += dp[i][_][__][___];
                        // } else if (j == 5) {
                        dp[i + 1][_][__][___ + 1] += dp[i][_][__][___];
                        // } else {
                        dp[i + 1][_ + 1][__ + 1][___] += dp[i][_][__][___];
                        // }
                    }
                }
            }
        }
        // }
    }

    std::cout << dp[N][cnt[2]][cnt[3]][cnt[5]].val() << "\n";
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