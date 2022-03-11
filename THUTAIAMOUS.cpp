#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()

using i64 = long long;

void jiangly_fan() {
	int n, k; std::cin >> n >> k;

	std::vector<std::vector<int>> A(8, std::vector<int> (8, 0));
	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 8; ++j) {
			std::cin >> A[i][j];
		}
	}

	std::vector<std::pair<int, int>> loc;
	std::vector<std::vector<bool>> ON(8, std::vector<bool> (8, false));
	for (int i = 0; i < k; ++i) {
		std::string lc; std::cin >> lc;

		int x = int(lc[0] - 'A');
		int y = int(lc[1] - '1');

		//std::cerr << y << " " << x << "\n";
		loc.push_back(std::make_pair(y, x));

		ON[y][x] = true;
	}
	int Base = 0;
	for (int i = 0; i < k; ++i) {
		Base = Base | (1 << i);
	}

	// std::cerr << Base << "\n";

	std::string IN; std::cin >> IN;
	int X = int(IN[0] - 'A');
	int Y = int(IN[1] - '1');

	int dx[8] = { -2, -2, -1, 1, 2, 2, -1, 1};
	int dy[8] = { -1, 1, -2, -2, -1, 1, 2, 2};

	auto calc = [&](auto self, int x, int y, int step, int base, std::vector<std::vector<int>> value) -> int {
		if (step == n) {
			return 0;
		}

		int answer = 0;

		for (int i = 0; i < 8; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && ny >= 0 && nx < 8 && ny < 8) {
				bool can = true;
				bool is = false;
				int c = -1;
				for (int j = 0; j < k; ++j) {
					if ((nx ^ loc[j].first || ny ^ loc[j].second)) {
						if (base >> j & 1) {
							if (loc[j].first == nx || loc[j].second == ny) {
								can = false;
							}

							if (std::abs(loc[j].first - nx) == std::abs(loc[j].second - ny)) {
								can = false;
							}
						}
					} else {
						is = true;
						c = j;
					}
				}
				if (can) {
					if (!is) {
						int val = value[nx][ny];
						value[nx][ny] = 0;
						answer = std::max(answer, val + self(self, nx, ny, step + 1, base, value));
						value[nx][ny] = val;
						continue;
					}
					base = base ^ (1 << c);
					answer = std::max(answer, 0 + self(self, nx, ny, step + 1, base, value));
					base = base ^ (1 << c);
				}
			}
		}

		return answer;
	};

	std::cout << calc(calc, Y, X, 0, Base, A) << "\n";
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int T = 1;
	//std::cin >> T;

	for (int i = 0; i < T; ++i) {
		jiangly_fan();
	}

	return 0;
}
