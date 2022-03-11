#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()

using i64 = long long;

void jiangly_fan() {
	std::string S; std::cin >> S;

	int Q; std::cin >> Q;

	auto sub3 = [&]() -> void {
		auto debug = [&](std::vector<int> dbg) -> void {
			std::cerr << "[";

			for (int i = 0; i < 26; ++i) {
				if (dbg[i]) {
					std::cerr << dbg[i] << char(i + 'A');
				}
			}

			std::cerr << "]\n";
		};

		std::vector<std::vector<int>> F(int(S.size()) + 7, std::vector<int> (26, 0));

		for (int i = 0; i < int(S.size()); ++i) {
			for (int j = 0; j < 26; ++j) {
				F[i + 1][j] = F[i][j];
			}

			++F[i + 1][int(S[i] - 'A')];
		}

		for (int i = 0; i < Q; ++i) {
			std::string X; std::cin >> X;

			std::vector<int> comp(26, 0);
			for (auto c : X) {
				++comp[int(c - 'A')];
			}

			std::vector<int> get(26, 0);
			for (int k = 0; k < 26; ++k) {
				get[k] = F[int(X.size())][k];
			}
			// debug(get);
			for (int j = 0; j <= int(S.size()) - int(X.size()); ++j) {
				// debug(get);
				if (get == comp) {
					std::cout << j + 1 << "\n";
					break;
				}
				--get[int(S[j] - 'A')];
				++get[int(S[int(X.size()) + j] - 'A')];
			}
		}
	};

	auto sub2 = [&]() -> void {
		std::vector <std::string> query;

		std::map<std::string, int> id;
		std::vector<int> answer(Q + 1, 1E9);

		for (int i = 0; i < Q; ++i) {
			std::string X; std::cin >> X;

			if (int(X.size()) > 6) {
				return;
			}

			std::sort(all(X));

			query.push_back(X);

			id[X] = i + 1;
		}

		int len = int(S.size());

		for (int i = 0; i < len; ++i) {
			std::string Fadd = "";

			for (int j = i; j < len; ++j) {
				if (int(Fadd.size()) >= 6) {
					break;
				}

				Fadd.push_back(S[j]);

				std::sort(all(Fadd));

				if (id[Fadd]) {
					answer[id[Fadd]] = std::min(answer[id[Fadd]], i);
				}
			}
		}

		for (int i = 0; i < Q; ++i) {
			std::cout << answer[id[query[i]]] + 1 << "\n";
		}
	};

	if (Q <= 1E3) {
		sub3();
	} else {
		sub2();
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
