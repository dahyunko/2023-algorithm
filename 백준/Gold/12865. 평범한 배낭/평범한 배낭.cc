/*평범한 배낭- 12865*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int N, K;

	cin >> N >> K;

    //이중 배열 dp
	vector<vector<int>>dp(N + 1, vector<int>(K + 1, 0));
	vector<int>W(N+1);//무게
	vector<int>V(N+1);//가치

	for (int i = 1; i <= N; i++) cin >> W[i] >> V[i];

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= K; j++) {
			if (j - W[i] >= 0) {
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - W[i]] + V[i]);
			}
			else dp[i][j] = dp[i - 1][j];
		}
	}
	
	cout << dp[N][K];
}