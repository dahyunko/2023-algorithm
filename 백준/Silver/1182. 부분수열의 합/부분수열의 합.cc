/*3*/
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>

using namespace std;

int N, S, result = 0;
int A[21];

void dfs(int cnt, int c, int sum, int j) {
	if (cnt == c) {
		if (sum == S) result++;
		return;
	}

	for (int i = j+1; i < N; i++) {
		dfs(cnt, c + 1, sum + A[i], i);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> S;

	for (int i = 0; i < N; i++) cin >> A[i];

	for (int t = 1; t <= N; t++) {
		for (int i = 0; i < N; i++) {
			dfs(t, 1, A[i], i);
		}
	}

	cout << result;
}