/*2293*/
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	int n, k;

	cin >> n >> k;

	vector<int>A(n);
	vector<int>dp(k+1,0);

	for (int i = 0; i < n; i++) cin>>A[i];

	dp[0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = A[i]; j <= k; j++) {
			dp[j] += dp[j - A[i]];
		}
	}

	cout << dp[k];
}