/*15652*/
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int N, M;
int ans[9] = {0};

void dfs(int cnt, int num) {
	if (cnt == M) {
		for (int i = 0; i < M; i++) {
			cout << ans[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = num; i <= N; i++) {
		ans[cnt] = i;
		dfs(cnt + 1, i);
	}
}

int main() {
	cin >> N >> M;
	vector<int>count(9, 0);
	dfs(0, 1);
}