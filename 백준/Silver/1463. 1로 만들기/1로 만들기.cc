/*1463*/
#include<limits.h>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	int N;
	
	cin >> N;
	vector<int> dp(N + 1, 0);

	dp[2] = 1;
	dp[3] = 1;
	for (int i = 4; i <= N; i++) {
		int a = INT_MAX, b = INT_MAX, c = INT_MAX;
		
		if (i % 3 == 0) a = dp[i / 3] + 1;
		if (i % 2 == 0) b = dp[i / 2] + 1;
		c = dp[i - 1] + 1;

		dp[i] = min(a, min(b, c));
	}
	cout << dp[N];
}