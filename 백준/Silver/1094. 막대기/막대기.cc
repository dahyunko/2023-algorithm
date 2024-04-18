/*1094*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <limits.h>
#include <cmath>

using namespace std;

int list[8] = { 1, 2, 4, 8, 16, 32, 64 };

int main() {
	int X;
	cin >> X;

	vector<int>dp(X + 1, INT_MAX);

	dp[0] = 0;
	for (int i = 0; i < 7; i++) {
		if (list[i] > X) {
			break;
		}

		dp[list[i]] = 1;
		for (int j = list[i] + 1; j <= X; j++) {
			dp[j] = min(dp[j], dp[j - list[i]] + dp[list[i]]);
		}
	}

	cout << dp[X];
}