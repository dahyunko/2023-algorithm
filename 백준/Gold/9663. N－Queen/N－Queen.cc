/*9336*/
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int N; 
int result = 0;
bool visited[15][15] = { false };
int ans[15][15] = { 0 };

void dfs(int cnt, int i) {
	if (cnt == N) {	result++; return; }
	if (i == N) return;

	for (int j = 0; j < N; j++) {
		if (!visited[i][j]) {
			int a = i, b = j;
			while (!visited[a][b]) {
				a--;
				b--;
				if (a < 0) { a = 0; b++; break; }
				if (b < 0) { b = 0; a++; break; }
			}
			if (visited[a][b]) continue;
			
			a = i, b = j;
			while (!visited[a][b]){
				a--;
				if (a < 0) { a = 0; break; }
			}
			if (visited[a][b]) continue;

			a = i, b = j;
			while (!visited[a][b]) {
				a--;
				b++;
				if (a < 0) { a = 0; b--; break; }
				if (b > N - 1) { b = N - 1; a++; break; }
			}
			if (visited[a][b]) continue;

			visited[i][j] = true;
			ans[i][j] = 1;
			dfs(cnt + 1, i + 1);
			visited[i][j] = false;
			ans[i][j] = 0;
		}
	}
}

int main() {
	cin >> N;
	dfs(0, 0);

	cout << result;
}