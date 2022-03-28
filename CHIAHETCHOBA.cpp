#include <bits/stdc++.h>

int main() {

	std::string s; std::cin >> s;
	std::set<std::string> unique;

	int n = int(s.size());

	for (int mask = 1; mask < (1 << n); ++mask) {
		std::vector<int> on;
		for (int i = 0; i < n; ++i) {
			if (!(mask >> i & 1)) {
				on.push_back(i);
			}
		}

		bool ok = true;
		for (int i = 0; i < int(on.size()) - 1; ++i) {
			if ((on[i + 1] - on[i]) ^ 1) {
				ok = false;

				break;
			}
		}

		if (!ok) {
			// std::cerr << int(on.size()) << "\n";

			continue;
		}

		std::string os = "";
		int fs = 0;

		for (int i = 0; i < n; ++i) {
			if (mask >> i & 1) {
				os += s[i];

				fs += int(s[i] - '0');
			}
		}

		// std::cerr << os << "\n";

		// if (os == "204") {
		// 	std::cout << ok << " " << int(on.size()) << "\n";
		// }

		if (fs % 3 == 0) {
			while (int(os.size()) > 1 && os[0] == '0') {
				os.erase(os.begin());
			}

			unique.insert(os);
		}
	}

	// for (auto val : unique) {
	// 	std::cerr << val << " ";
	// }
	// puts("");

	std::cout << int(unique.size()) << "\n";

	return 0;
}
