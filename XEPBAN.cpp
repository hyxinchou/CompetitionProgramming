#include <bits/stdc++.h>

int main() {

	int P; std::cin >> P;
	while (P--) {
		int T, N; std::cin >> T >> N;
		std::vector<int> A(T);
		for (int i = 0; i < T; ++i) {
			std::cin >> A[i];
		}
		std::sort(A.begin(), A.end());
		int l = 0, r = 1E9;
		while (r - l > 1) {
			int m = (l + r) / 2;
			bool ok = true;
			int pre = A[0];
			for (int i = 1; i < N; ++i) {
				int l = std::lower_bound(A.begin(), A.end(), pre + m) - A.begin();
				if (l >= 0 && l < T && A[l] >= pre + m) {
					pre = A[l];
				} else {
					ok = false;
				}
			}
			if (ok) {
				l = m;
			} else {
				r = m;
			}
		}
		std::cout << l << "\n";
	}

	return 0;
}
