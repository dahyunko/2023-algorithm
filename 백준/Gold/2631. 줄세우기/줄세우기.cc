/*2631*/
//LIS
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
#include<limits.h>
#include<cmath>

using namespace std;

int main() {
	int N;
	cin >> N;

	vector<int>list(N);
	vector<int>dp(N, 1);
	for (int i = 0; i < N; i++) cin >> list[i];

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < i; j++) {
			if (list[i] > list[j]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}

	int m = *max_element(dp.begin(), dp.end());
	cout << N - m;
}