#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
#include<limits.h>
#include<cmath>

using namespace std;

int main() {
	int N, M, start, end;
	cin >> N >> M;

	vector<int> A(M);
	vector<int> W(M, 0);// 간격 
	for (int i = 0; i < M; i++) {
		cin >> A[i];
		if (i == 0) start = A[i];
		else W[i] = A[i] - A[i-1];
	}
	end = N - A[M - 1];

	sort(W.begin(), W.end());

	int ans = W[M - 1];
	ans = ans / 2 + ans % 2;

	ans = max(ans, start);
	ans = max(ans, end);
	
	cout << ans;
}