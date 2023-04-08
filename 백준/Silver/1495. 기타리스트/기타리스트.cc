/*기타 리스트- 1495*/
#include<queue>
#include <iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<string>

using namespace std;

int main() {
	int N, S, M;

	cin >> N >> S >> M;

	vector<int>test(N+1);
	vector<vector<bool>>dp(N+1, vector<bool>(M+1, false));
	for (int i = 1; i <= N; i++) cin >> test[i];

	dp[0][S] = true;

	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= M; j++) {
			if (!dp[i - 1][j]) continue;
			if (j - test[i] >= 0) dp[i][j - test[i]] = true;
			if (j + test[i] <= M) dp[i][j + test[i]] = true;
		}
	}

	for (int j = M; j >=0 ; j--) {
		if (dp[N][j]) { cout << j; break; }
        if (j == 0 && !dp[N][j]) cout << -1;
	}
}