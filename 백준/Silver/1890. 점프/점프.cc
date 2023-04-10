#include<queue>
#include <iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<string>
#include <limits.h>

using namespace std;

typedef pair<int, int> info;
int main() {
	int N;

	cin >> N;
	vector<vector<int>>game(N, vector<int>(N));
	vector<vector<long>>dp(N, vector<long>(N, 0));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) cin >> game[i][j];
	}

	dp[0][0] = 1;

	queue<info> q;
	q.push(info(0, 0));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (dp[i][j] == 0) continue;
			if (i == N - 1 && j == N - 1) continue;
			
			int t = game[i][j];
			if (j + t < N) dp[i][j + t] += dp[i][j];
			if (i + t < N) dp[i + t][j] += dp[i][j];
		}
	}
	cout << dp[N - 1][N - 1];	
}