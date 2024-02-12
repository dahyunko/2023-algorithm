#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <sstream>

using namespace std;

int N, M;
char c1[1001], c2[1001];
vector<vector<int>>dp(1001, vector<int>(1001, -1));

int check_string(int now, int j) {
	// 기저 조건
	if (now == N + 1 || j == M + 1) return 0;
	if (dp[now][j] > -1) return dp[now][j];

	if (c1[now] == c2[j]) {
		return dp[now][j] = check_string(now + 1, j + 1) + 1;
	}
	return dp[now][j] = max(check_string(now + 1, j), check_string(now, j + 1));
}


int main() {
	string s1, s2;

	cin >> s1;
	cin >> s2;

	N = s1.length();
	M = s2.length();

	for (int i = 0; i < N; i++) c1[i + 1] = s1[i];
	for (int i = 0; i < M; i++) c2[i + 1] = s2[i];
	
	cout << check_string(1, 1);
}