#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()

using i64 = long long;

void jiangly_fan() {
	i64 n; std::cin >> n;

    i64 cnt = 1;
    i64 depth = 0;

    while (n >= cnt) {
        n -= cnt;

        cnt += 2;

        ++depth;
    }

    // std::cout << n << "\n";

    depth += n ? 1 : 0;

    std::cout << depth << " ";

    if (~depth & 1) {
        std::cout << n << "\n";
    } else {
        if (n) {
            std::cout << cnt - n + 1 << "\n";
        } else {
            std::cout << 1 << "\n";
        }
    }

    i64 r, c; std::cin >> r >> c;

    cnt = 2  * (r - 1) - 1;

    i64 answer = (cnt + 1) * ((cnt - 1) / 2 + 1) / 2;

    // std::cerr << cnt << "\n";
    cnt += 2;

    if (r & 1) {
        std::cout << answer + cnt - c + 1 << "\n";
    } else {
        std::cout << answer + c << "\n";
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
