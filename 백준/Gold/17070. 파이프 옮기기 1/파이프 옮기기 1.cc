/*파이프 옲기기1- 17070*/
#include<iostream>
#include<string>
#include<cmath>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>

using namespace std;

int n, ans = 0;

void dfs(vector<vector<int>>& graph, vector<vector<bool>>& visited, int a1, int a2, int b1, int b2) {
	if (b1 == n - 1 && b2 == n - 1) { ans++; return; }

	int flag = 0;
	//가로: 1, 세로: 2, 대각선:3
	if (a1 == b1) flag = 1;
	else if (a2 == b2) flag = 2;
	else flag = 3;

	if (flag == 1) {//가로
		if (b2 + 1 < n && graph[b1][b2 + 1] == 0) {
			//가로
			dfs(graph, visited, b1, b2, b1, b2 + 1);
			//대각선
			if (b1 + 1 < n && graph[b1 + 1][b2] == 0 && graph[b1 + 1][b2 + 1] == 0) dfs(graph, visited, b1, b2, b1 + 1, b2 + 1);
		}
	}
	else if (flag == 2) {//세로
		if (b1 + 1 < n && graph[b1 + 1][b2] == 0) {
			//세로
			dfs(graph, visited, b1, b2, b1 + 1, b2);
			//대각선
			if (b2 + 1 < n && graph[b1][b2 + 1] == 0 && graph[b1 + 1][b2 + 1] == 0) dfs(graph, visited, b1, b2, b1 + 1, b2 + 1);
		}
	}
	else if (flag == 3) {
		//가로
		if (b2 + 1 < n && graph[b1][b2 + 1] == 0) dfs(graph, visited, b1, b2, b1, b2 + 1);
		// 세로
		if (b1 + 1 < n && graph[b1 + 1][b2] == 0) dfs(graph, visited, b1, b2, b1 + 1, b2);
		//대각선
		if (b1 + 1 < n && b2 + 1 < n && graph[b1 + 1][b2] == 0 && graph[b1][b2 + 1] == 0 && graph[b1 + 1][b2 + 1] == 0) dfs(graph, visited, b1, b2, b1 + 1, b2 + 1);
	}	
}

int main() {
	cin >> n;
	vector<vector<int>> graph(n, vector<int>(n));
	vector<vector<bool>> visited(n, vector<bool>(n, false));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) cin >> graph[i][j];
	}

	dfs(graph, visited, 0, 0, 0, 1);

	cout << ans;	
}