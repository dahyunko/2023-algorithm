#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>

using namespace std;

static int MAX_NUM = 1000001;
int N;
vector<vector<int>> home(1001, vector<int>(3));
vector<vector<long>> dp(1001, vector<long>(3, MAX_NUM));

long findMin(int b) { // 
	for (int i = 1; i < N-1; i++) {
		if (i == N - 2 && b == 0) {
			dp[i][0] = MAX_NUM;
		}
		else {
			dp[i][0] = home[i][0] + min(dp[i - 1][1], dp[i - 1][2]);
		}
		
		if (i == N - 2 && b == 1) {
			dp[i][1] = MAX_NUM;
		}
		else {
			dp[i][1] = home[i][1] + min(dp[i - 1][0], dp[i - 1][2]);
		}
		if (i == N - 2 && b == 2) {
			dp[i][2] = MAX_NUM;
		}
		else {
			dp[i][2] = home[i][2] + min(dp[i - 1][0], dp[i - 1][1]);
		}
	}

	return *min_element(dp[N - 2].begin(), dp[N - 2].begin() + 3);
}

int main() {
	long result = MAX_NUM;
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> home[i][0] >> home[i][1] >> home[i][2];
	
	dp[0][0] = home[0][0] + home[N-1][1];
	dp[0][1] = MAX_NUM;
	dp[0][2] = MAX_NUM;
	result = min(result, findMin(1));

	dp[0][0] = home[0][0] + home[N - 1][2];
	dp[0][1] = MAX_NUM;
	dp[0][2] = MAX_NUM;
	result = min(result, findMin(2));

	dp[0][0] = MAX_NUM;
	dp[0][1] = home[0][1] + home[N - 1][0];
	dp[0][2] = MAX_NUM;
	result = min(result, findMin(0));

	dp[0][0] = MAX_NUM;
	dp[0][1] = home[0][1] + home[N - 1][2];
	dp[0][2] = MAX_NUM;
	result = min(result, findMin(2));

	dp[0][0] = MAX_NUM;
	dp[0][1] = MAX_NUM;
	dp[0][2] = home[0][2] + home[N - 1][0];
	result = min(result, findMin(0));

	dp[0][0] = MAX_NUM;
	dp[0][1] = MAX_NUM;
	dp[0][2] = home[0][2] + home[N - 1][1];
	result = min(result, findMin(1));
	
	cout << result;

}