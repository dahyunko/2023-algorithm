/*감소하는 수*/
#include<iostream>
#include<string>
#include<cmath>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>

using namespace std;

long result = 0, cnt=-1;
vector<int>list(100);
vector<bool>visited(11, false);
bool flag;

void dfs(int c, int N, int m) {
	if (c == m) {
		cnt++;
		if (cnt == N) {
			for (int i = 0; i < m; i++) cout << list[i];
			flag = true;
		}
		return;
	}

	for (int i = 0; i < 10; i++) {
		if (c == 0) {
			visited[i] = true;
			list[c] = i;
			dfs(c+1, N, m);
			visited[i] = false;
		}
		if (c > 0) {
			if (list[c - 1] > i) {
				visited[i] = true;
				list[c] = i;
				dfs(c + 1, N, m);
				visited[i] = false;
			}
		}
	}
}

int main() {
	int N;
	
	cin >> N;

	for (int i = 1; i <= 100; i++) {
		dfs(0, N, i);
		fill(visited.begin(), visited.end(), false);
		if (flag) break;
	}

	if (!flag) cout << -1;
}