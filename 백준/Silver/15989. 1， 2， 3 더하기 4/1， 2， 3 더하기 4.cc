/*1, 2, 3 더하기 4- 15989*/
#include<queue>
#include <iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<string>

using namespace std;

int main() {
	int T;
	
	cin >> T;
	vector<int>test(T);
	for (int i = 0; i < T; i++) cin >> test[i];

	int m = *max_element(test.begin(), test.end());
	vector<int>dp(m + 1, 0);

	dp[0] = 1;
	for (int i = 1; i <= 3; i++) {
		for (int j = i; j <= m ; j++) dp[j] += dp[j - i];
	}
	
	for (int i = 0; i < T; i++) cout << dp[test[i]] <<'\n';
}