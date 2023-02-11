/*해결*/
#include <iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<string>

using namespace std;

int main() {
	int N;

	cin >> N;
	vector<int> A(N + 1, 0);
	vector<int> dp(N + 1, 0);

	for (int i = 1; i <= N; i++) cin >> A[i];

	//solution
	dp[1] = A[1];
	dp[2] = A[1] + A[2];
	dp[3] = max(dp[1] + A[3], A[2] + A[3]);

	for (int i = 4; i <= N; i++) {
		dp[i] = max(dp[i - 2] + A[i], dp[i - 3] + A[i - 1] + A[i]);
	}
	
	cout << dp[N];
}