#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()

using i64 = long long;

void jiangly_fan() {

}

std::bitset<10000007> prime;

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int T = 1;
	std::cin >> T;

	// prime.set();

	prime[0] = prime[1] = 1;

	for (int i = 2; i * i <= 10000000; ++i) {
		if (!prime[i]) {
			for (int j = i * i; j <= 10000000; j += i) {
				prime[j] = 1;
			}
		}
	}

	std::vector<int> onlyPrime;
	onlyPrime.push_back(2);

	for (int i = 3; i <= 10000000; i += 2) {
		if (!prime[i]) {
			onlyPrime.push_back(i);
		}
	}

	// for (int i = 0; i < 10; ++i) {
	// 	std::cerr << onlyPrime[i] << " \n"[i == 9];
	// }

	auto Legendre = [&](int num, int p) -> int {
		int answer = 0;

		while (num) {
			num /= p;
			answer += num;
		}

		return answer;
	};

	for (int i = 0; i < T; ++i) {
		// jiangly_fan();
		int a, b, c, d; std::cin >> a >> b >> c >> d;


		bool ok = true;
// 		std::vector<int> F;
// 		std::set<int> Set;
		std::vector<int> C(10000007, 0);
		for (auto val : onlyPrime) {
			if (val > b) {
				break;
			}

			int fx = Legendre(b, val) - Legendre(a - 1, val);


			if (fx) {
				// F.push_back(val);
				// Set.insert(val);
				// std::cerr << val << " " << fx << "\n";
				int fy = Legendre(d, val) - Legendre(c - 1, val);

				if (fy < fx) {
					ok = false;
					break;
				}
				// C[val] = fx;
			}
		}

		// std::cerr << "\n";



// 		for (auto val : onlyPrime) {
// 			if (val > d) {
// 				break;
// 			}

// 			int fx = Legendre(d, val) - Legendre(c - 1, val);

// 			if (fx) {

// 				// std::cerr << val << " " << fx << "\n";

// 				if (C[val] > fx) {
// 					ok = false;
// 					break;
// 				}

// 				Set.erase(val);
// 			}
// 		}

// 		ok = !(Set.size());

		std::cout << (ok ? "YES\n" : "NO\n");
	}

	return 0;
}