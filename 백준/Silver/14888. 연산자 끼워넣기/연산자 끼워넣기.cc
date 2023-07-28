/*9*/
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include <queue>
#include <cmath>
#include<limits.h>
using namespace std;

int N;
int A[12];
int B[4];
int use[4] = { 0 };
int ans_max = INT_MIN, ans_min = INT_MAX;

void dfs(int cnt, int sum) {
	if (cnt == N - 1) {
		ans_max = max(sum, ans_max);
		ans_min = min(sum, ans_min);
		return;
	}

	if (use[0] < B[0]) {
		use[0]++;
		dfs(cnt + 1, sum + A[cnt + 1]);
		use[0]--;
	}
	if (use[1] < B[1]) {
		use[1]++;
		dfs(cnt + 1, sum - A[cnt + 1]);
		use[1]--;
	}
	if (use[2] < B[2]) {
		use[2]++;
		dfs(cnt + 1, sum * A[cnt + 1]);
		use[2]--;
	}
	if (use[3] < B[3]) {
		use[3]++;
		if (sum < 0) {//음수
			int temp = sum;
			temp *= -1;
			temp /= A[cnt + 1];
			dfs(cnt + 1, temp * -1);
		}
		else dfs(cnt + 1, sum / A[cnt + 1]);
		use[3]--;
	}
}


int main() {
	cin >> N;
	for (int i = 0; i < N; i++) cin >> A[i];
	for (int i = 0; i < 4; i++)cin >> B[i];

	dfs(0, A[0]);
	
	cout << ans_max<<'\n'<<ans_min;
}