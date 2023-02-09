/*1912*/
#include <iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<string>

using namespace std;

int main() {
	int N;
	cin >> N;
	vector<long> A(N, 0);
	vector<long> dp(N, 0);

	for (int i = 0; i < N; i++) cin >> A[i];

	dp[0] = A[0];
	for (int i = 1; i < N; i++) {
		dp[i] = max(dp[i-1] + A[i], A[i]);
	}
	cout << *max_element(dp.begin(), dp.end());
}