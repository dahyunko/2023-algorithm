/*15652*/
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int N, M;
int ans[9] = {0};

void dfs(int cnt, vector<int>& count) {
	if (cnt == M) {
		for (int i = 0; i < M; i++) {
			cout << ans[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = 1; i <= N; i++) {
		if (count[i] <= M) {
			if (cnt == 0) ans[cnt] = i;
			else if (cnt > 0 && ans[cnt - 1] <= i) ans[cnt] = i;
			else continue;
			count[i]++;
			dfs(cnt + 1, count);
			count[i]--;
		}
	}
}

int main() {
	cin >> N >> M;
	vector<int>count(9, 0);
	dfs(0, count);
}