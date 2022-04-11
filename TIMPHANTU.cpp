#include <bits/stdc++.h>

using i64 = long long;

int main() {
	
	int N;
	std::cin >> N;
	
	std::vector<int> a(N);
	for (int i = 0; i < N; ++i) {
		std::cin >> a[i];
	}
	
	std::sort(a.begin(), a.end());
	a.erase(std::unique(a.begin(), a.end()), a.end());
	
	int answer = 0;
	
	for (auto v : a) {
		if (answer != v) {
			break;
		} else {
			++answer;
		}
	}
	
	std::cout << answer << "\n";
	
	return 0;
}
