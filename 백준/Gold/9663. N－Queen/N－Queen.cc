/*16*/
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include <queue>
#include <cmath>
#include<limits.h>

using namespace std;

int N, ans = 0;
int col[16];

void search(int t) {
	if (t == N) {
		ans++;
		return;
	}

	for (int i = 0; i < N; i++) {
		col[t] = i;
		bool can = true;
		for (int j = 0; j < t; j++) {
			//대각선 같은 라인 확인하는 부분
			//**아이디어!!, 이중 배열로 돌리면 시간초과 발생함
			if (col[t] == col[j] || abs(col[t] - col[j]) == t - j) {
				can = false;
				break;
			}
		}
		if (can) search(t + 1);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;

	search(0);
	cout << ans;
}