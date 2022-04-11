//https://nbk.homes/problem/sumzero
#include <bits/stdc++.h>

int main() {

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }

    std::vector<std::vector<std::pair<int, int>>> f(5E6 + 7);

    int base = 3E6;

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            f[a[i] + a[j] + base].push_back(std::make_pair(i, j));
        }
    }

    int answer = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int l = std::lower_bound(f[-a[i] - a[j] + base].begin(), f[-a[i] - a[j] + base].end(), std::make_pair(j + 1, 0)) - f[-a[i] - a[j] + base].begin();

            if (l >= 0 && l < int(f[-a[i] - a[j] + base].size())) {
                answer += int(f[-a[i] - a[j] + base].size()) - l;
            }
        }
    }

    std::cout << answer << "\n";

    return 0;
}
