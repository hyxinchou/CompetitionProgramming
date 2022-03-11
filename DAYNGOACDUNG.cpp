#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()

using i64 = long long;

constexpr int P = 998244353;

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

struct nCr_with_Pascal_Triangle {
    std::vector<std::vector<Z>> C;
    int N;
    nCr_with_Pascal_Triangle(int _N) {
        N = _N;
        C = std::vector<std::vector<Z>> (_N + 1, std::vector<Z>(_N + 1, 0));
    }
    void build() {
        C[0][0] = 1;
        for (int i = 1; i <= N; ++i) {
            C[i][0] = 1;
            for (int j = 1; j < i + 1; ++j) {
                C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
            }
        }
    }
    Z nCr(int n, int r) {
        return C[n][r];
    }
};

void jiangly_fan() {
    std::string S; std::cin >> S;

    int len = int(S.size());

    std::vector<std::string> Comp;
    std::stack<char> Stack;
    std::string g = "", _empty = "";

    for (auto c : S) {
        if (Stack.empty()) {
            if (g.size()) {
                Comp.push_back(g);

                g = _empty;
            }

            Stack.push(c);
        } else {
            if (Stack.top() == '(' && c == ')') {
                Stack.pop();
            } else {
                Stack.push(c);
            }
        }

        g += c;
    }

    nCr_with_Pascal_Triangle F(1007);
    F.build();

    const int Nxm = 1E5;

    Comp.push_back(g);

    Z answer = 1;

    std::vector<Z> ret;

    for (auto v : Comp) {
        
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