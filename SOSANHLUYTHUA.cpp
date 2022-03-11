#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()

using i64 = long long;

void jiangly_fan() {
	int X, Y, Z; std::cin >> X >> Y >> Z;

	if (!Z) {
		std::cout << "=\n";
		return;
	}

	if (~Z & 1) {
		X = std::abs(X);
		Y = std::abs(Y);
	}

	std::cout << (X > Y ? ">" : (X == Y ? "=" : "<")) << "\n";
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