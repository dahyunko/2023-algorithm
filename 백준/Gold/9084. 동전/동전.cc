/*동전- 9084*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int T, N, M;

	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> N;
		vector<int>coins(N);
		for (int i = 0; i < N; i++) cin >> coins[i];
		cin >> M;

		//dp사용
		vector<int>dp(M + 1, 0);
		dp[0] = 1;
		for (int i = 0; i < N; i++) {
			for (int j = coins[i]; j <= M; j++) {
				dp[j] += dp[j - coins[i]];
			}
		}
		cout << dp[M]<<'\n';
	}
}