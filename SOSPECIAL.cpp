#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()

using i64 = long long;

void jiangly_fan() {
	std::bitset<4000007> prime;
    prime.set();

    prime[0] = prime[1] = 0;

    for (int i = 2; i * i <= 3000000; ++i) {
        if (prime[i]) {
            for (int j = i * i; j <= 3000000; j += i) {
                prime[j] = 0;
            }
        }
    }

    std::vector<int> f;

    auto check = [&](int x) -> bool {
        int sum = 0;

        while (x) {
            sum += x % 10;

            x /= 10;
        }

        return sum % 5 ? false : true;
    };

    for (int i = 5; i <= 3000000; i += 2) {
        if (prime[i] && check(i)) {
            f.push_back(i);
        }
    }

    // for (int i = 0; i < 5; ++i) {
    //     std::cout << f[i] << " \n"[i == 4];
    // }

    int T; std::cin >> T;
    while (T--) {
        int l, r; std::cin >> l >> r;

        int a = std::lower_bound(all(f), l) - f.begin();
        int b = std::upper_bound(all(f), r) - f.begin();
        --b;

        std::cout << b - a + 1 << "\n";
    }
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
