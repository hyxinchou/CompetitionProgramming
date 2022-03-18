#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()

using i64 = long long;

//Source : https://cp-algorithms.com/string/prefix-function.html
std::vector<int> prefix_function(std::string s) {
	int n = (int)s.length();
	std::vector<int> pi(n);
	for (int i = 1; i < n; i++) {
		int j = pi[i - 1];
		while (j > 0 && s[i] != s[j])
			j = pi[j - 1];
		if (s[i] == s[j])
			j++;
		pi[i] = j;
	}
	return pi;
}


void jiangly_fan() {
	std::vector<std::string> A(3);

	std::cin >> A[0] >> A[1] >> A[2];
	for (auto &c : A[0]) {
		c = char(std::tolower(c));
	}
	for (auto &c : A[1]) {
		c = char(std::tolower(c));
	}
	for (auto &c : A[2]) {
		c = char(std::tolower(c));
	}

	std::vector<int> p(3, 0);
	std::iota(all(p), 0);

	int answer = 1E9;

	do {
		auto s1 = A[p[0]];

		// std::reverse(all(s1));

		s1 = A[p[1]] + "#" + s1;

		auto d1 = prefix_function(s1);

		// std::cerr << s1 << " " << A[p[1]] << " ";

		// std::cerr << s1 << "\n";
		// for (auto v : d1) {
		// 	std::cerr << v << " ";
		// }

		// std::cout << "\n\n";

		int len1 = d1.back();
		// for (int i = 0; i < std::min(int(A[p[0]].size()), int(A[p[1]].size())); ++i) {
		// 	std::cerr << s1[i] << " " << A[p[1]][i] << " ";

		// 	if (s1[i] != A[p[1]][i]) {
		// 		break;
		// 	}

		// 	++len1;
		// }

		// std::cerr << len1 << " ";

		s1 = A[p[2]];

		// std::reverse(all(s1));

		s1 = s1 + "#" +  A[p[1]];

		auto d2 = prefix_function(s1);

		// std::cerr << s1 << "\n";
		// for (auto v : d2) {
		// 	std::cerr << v << " ";
		// }

		// std::cout << "\n\n";

		int len2 = d2.back();

		// std::cerr << s1 << " " << A[p[2]] << " ";

		// int len2 = 0;
		// for (int i = 0; i < std::min(int(A[p[2]].size()), int(A[p[1]].size())); ++i) {
		// 	if (s1[i] != A[p[2]][i]) {
		// 		break;
		// 	}

		// 	++len2;
		// }

		// std::cerr << len2 << "\n";

		answer = std::min(answer, int(A[0].size()) + int(A[1].size()) + int(A[2].size()) - len1 - len2);
	} while (std::next_permutation(all(p)));

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
