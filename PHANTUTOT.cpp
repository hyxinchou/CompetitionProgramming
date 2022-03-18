#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()

using i64 = long long;

void jiangly_fan() {
	int n; std::cin >> n;

	std::vector<int> A(n);
	for (auto &a : A) {
		std::cin >> a;

		a += 1E6;
	}

	std::vector<int> f(3E6, 1E9);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			f[A[i] + A[j] - 1E6] = std::min(f[A[i] + A[j] - 1E6], std::max(i, j));
		}
	}

	// std::cout << "1";
	// return;

	int answer = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < i; ++j) {
			if ((A[j] - 1E6) * 3 == A[i] - 1E6) {
				// std::cout << A[i] << " ";
				++answer;
				break;
			}

			if (f[A[i] - A[j] + 1E6] < i) {
				// std::cout << A[i] << " ";
				++answer;
				break;
			}
		}
	}

	std::cout << answer << "\n";
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
