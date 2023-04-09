/*BOJ- 12026*/
#include <limits.h>
#include<queue>
#include <iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<string>

using namespace std;
typedef pair<char, int> info;

int main() {
	int N;
	string sen;

	cin >> N;
	cin >> sen;
	
	vector<info>dp;

	for (int i = 0; i < N; i++) {
		dp.push_back(info(sen[i], INT_MAX));
	}

	dp[0].second = 0;
	for (int i = 0; i < N-1; i++) {
		if (dp[i].second == INT_MAX) continue;
		char c;
		if (dp[i].first == 'B') c = 'O';
		if (dp[i].first == 'O') c = 'J';
		if (dp[i].first == 'J') c = 'B';

		for (int j = i + 1; j < N; j++) {
			if (dp[j].first == c) {
				int temp = j - i;
				dp[j].second = min(dp[j].second, dp[i].second + temp * temp);
			}
		}
	}

	if (dp[N - 1].second == INT_MAX)cout << -1;
	else cout<< dp[N - 1].second;
}