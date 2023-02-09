#include <iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<string>

using namespace std;

int main() {
	int N;

	cin >> N;
	vector<vector<int>>A(N, vector<int> (N));
	vector<vector<long>>dp(N,vector<long> (3));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 3; j++) cin >> A[i][j];
	}

	dp[0][0] = A[0][0];
	dp[0][1] = A[0][1];
	dp[0][2] = A[0][2];

	for (int i = 1; i < N; i++) {
		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + A[i][0];
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + A[i][1];
		dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + A[i][2];
	}

	cout << *min_element(dp[N - 1].begin(), dp[N - 1].end());
}