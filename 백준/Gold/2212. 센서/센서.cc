/*2212--- 모름*/
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
#include<limits.h>
#include<cmath>

using namespace std;

int main() {
	int N, K, result = 0;
	cin >> N >> K;

	vector<int>A(N);
	vector<int>ans;

	for (int i = 0; i < N; i++) cin >> A[i];
	sort(A.begin(), A.end());

	for (int i = 0; i < N - 1; i++) ans.push_back(abs(A[i] - A[i + 1]));
	sort(ans.begin(), ans.end());

	for (int i = 0; i < N - K; i++) result += ans[i];

	cout << result;
}