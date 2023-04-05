/*퇴사 2- 15486*/
#include<queue>
#include <iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<string>

using namespace std;

typedef pair<int, int> info;

int main() {
	int N;

	cin >> N;
	vector<info>sche(N + 1);
	vector<int>dp(N + 1, 0);

	for (int i = 1; i <= N; i++) {
		int t, p;
		cin >> t >> p;

		sche[i].first = t;
		sche[i].second = p;
	}

	for (int i = 1; i <= N; i++) {
		dp[i] = max(dp[i - 1], dp[i]);
		int tmp = i + sche[i].first - 1;
		if (tmp > N) continue;
		dp[tmp] = max(dp[tmp], dp[i - 1] + sche[i].second);
	}

	cout << dp[N];
}