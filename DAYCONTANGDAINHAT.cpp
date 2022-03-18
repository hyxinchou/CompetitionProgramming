#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()

using i64 = long long;

void jiangly_fan() {
	int n; std::cin >> n;

	std::vector<int> A(n);
	for (auto &a : A) {
		std::cin >> a;
	}

	std::vector<int> answer;

	for (auto &a : A) {
		int l = std::lower_bound(all(answer), a) - answer.begin();

		if (l < int(answer.size())) {
			answer[l] = a;
		} else {
			answer.push_back(a);
		}
	}

	std::cout << int(answer.size()) << "\n";
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
