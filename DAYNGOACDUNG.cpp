#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()

using i64 = long long;

constexpr int P = 2012;

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
    std::string S; std::cin >> S;

    int len = int(S.size());

    std::vector<int> convert;
    for (auto c : S) {
        convert.push_back(c == '(' ? 1 : -1);
    }

    std::vector<int> pref_count(len + 1, 0);
    for (int i = 0; i < len; ++i) {
        pref_count[i + 1] = pref_count[i] + convert[i];
    }
    // for (auto v : convert) {
    //     std::cout << v << " ";
    // }
    // std::cout << "\n";

    std::vector<std::vector<Z>> dp(len + 1, std::vector<Z> (len + 1, 0));
    dp[0][0] = 1;

    for (int i = 0; i < len; ++i) {
        for (int msk1 = 0; msk1 < len; ++msk1) {
            int msk2 = pref_count[i] - msk1;

            if (msk2 >= 0 && msk1 + convert[i] >= 0) {
                dp[i + 1][msk1 + convert[i]] += dp[i][msk1];
            }

            if (msk2 + convert[i] >= 0) {
                dp[i + 1][msk1] += dp[i][msk1];
            }
        }
    }

    std::cout << dp[len][0].val() << "\n";
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
