/*2225*/
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

long mod = 1000000000;

int main() {
	int N, K;
	cin >> N >> K;

	int n = N + K;
	vector<vector<int>> dp(n, vector<int>(n));
	
	dp[0][0] = 1;
	for (int i = 1; i < n; i++) {
		dp[i][i] = 1;
		dp[i][0] = 1;
		dp[i][1] = i;
	}

	for (int i = 2; i < n; i++) {
		for (int j = 1; j <= i; j++) {
			dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1])%mod;
		}
	}
	
	cout << dp[n-1][K-1];
}
