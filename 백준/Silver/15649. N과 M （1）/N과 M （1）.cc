/*15649*/
#include <iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

int N, M;

void dfs(vector<int>& ans, vector<bool>& visited, int cnt) {
	if (cnt == M) {
		for (int i = 0; i < M; i++) cout << ans[i]<< ' ';
		cout << '\n';
		return;
	}
	for (int i = 1; i <= N; i++) {
		if (visited[i] == false) {
			visited[i] = true;
			ans[cnt] = i;
			dfs(ans, visited, cnt + 1);
			visited[i] = false;
		}
	}
}


int main() {
	cin >> N >> M;

	vector<bool>visited(N + 1, false);
	vector<int>ans(M);
	dfs(ans, visited, 0);
}