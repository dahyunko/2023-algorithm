#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <limits.h>

using namespace std;
/* 6198 */

int main() {
	int N;
	cin >> N;
	vector<long long> build(N, 0);
	vector<int> D(N, 0);

	for (int i = 0; i < N; i++) {
		long long now;
		cin >> now;
		build[i] = now;
	}

	long long result = 0;
	int prev = N - 1;
	for (int i = N - 2; i >= 0; i--) {
		while (build[i] > build[prev]) {
			D[i] += D[prev] + 1;

			prev += D[prev] + 1;
			if (prev >= N) break;
		}

		result += D[i];
		prev = i;
	}

	 cout << result;
}