/*1328*/
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<cmath>
#include<tuple>
#include<limits.h>

using namespace std;
typedef long long ll;

ll mod = 1000000007;

int main() {
	int N, L, R;
	cin >> N >> L >> R;

	ll dp[101][101][101]={0};

	dp[1][1][1] = 1;

	for (int i = 2; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			for (int t = 1; t <= N; t++) {
				dp[i][j][t] = (dp[i - 1][j - 1][t] + dp[i - 1][j][t - 1] + dp[i - 1][j][t] * (i - 2)) % mod;
			}
		}
	}

	cout << dp[N][L][R];
}