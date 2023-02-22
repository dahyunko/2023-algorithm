/*11502*/
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int>dp(N+1, 0);

	for (int i = 1; i <= N; i++) cin >> dp[i];

	for (int i = 2; i <= N; i++) {
		for (int j = 1;  j<= i; j++) {
			for (int t = 1; t <= i; t++) {
				if (j + t == i) {
					dp[i] = max(dp[i], dp[j]+dp[t]);
					break;
				}
			}
		}
	}
	cout << dp[N];
}