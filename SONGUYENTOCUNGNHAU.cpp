#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()

using i64 = long long;

void jiangly_fan() {
	int N, M; std::cin >> N >> M;

	std::vector<int> A(N);

	for (auto &a : A) {
		std::cin >> a;
	}

	std::vector<int> Gprime(100007, 0);
	std::iota(all(Gprime), 0);

	for (int i = 2; i * i <= 100000; ++i) {
		if (Gprime[i] == i) {
			for (int j = i * i; j <= 100000; j += i) {
				Gprime[j] = i;
			}
		}
	}

	std::set<int> Set;

	for (auto i : A) {
		int curr = i;

		while (curr > 1) {
			Set.insert(Gprime[curr]);

			curr /= Gprime[curr];
		}
	}

	std::vector<int> answer;

	for (int i = 1; i <= M; ++i) {
		int curr = i;
		bool ok = true;

		while (curr > 1) {
			if (Set.count(Gprime[curr])) {
				ok = false;

				break;
			}

			curr /= Gprime[curr];
		}

		if (ok) {
			answer.push_back(i);
		}
	}

	std::cout << int(answer.size()) << "\n";

	for (auto v : answer) {
		std::cout << v << "\n";
	}
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