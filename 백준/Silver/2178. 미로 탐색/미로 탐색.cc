#include<queue>
#include <iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<string>

using namespace std;

/*미로탐색- 2178*/
#include<limits.h>
#include<tuple>

typedef tuple<int, int, int>info;

int N, M, cnt;

void bfs(vector<string>& maze, vector<vector<bool>>& visited, int v1, int v2) {
	visited[v1][v2] = true;

	queue<info>q;
	q.push(make_tuple(1, v1, v2));
	while (!q.empty()) {
		info v = q.front();
		q.pop();

		int c = get<0>(v);
		v1 = get<1>(v);
		v2 = get<2>(v);
		if (v1 == N - 1 && v2 == M - 1) { cnt = c; break; }

		if (v1 + 1 < N && maze[v1 + 1][v2] == '1' && !visited[v1 + 1][v2]) {
			visited[v1 + 1][v2] = true;
			q.push(make_tuple(c + 1, v1 + 1, v2));
		}
		if (v1 - 1 >= 0 && maze[v1 - 1][v2] == '1' && !visited[v1 - 1][v2]) {
			visited[v1 - 1][v2] = true;
			q.push(make_tuple(c + 1, v1 - 1, v2));
		}
		if (v2 + 1 < M && maze[v1][v2 + 1] == '1' && !visited[v1][v2 + 1]) {
			visited[v1][v2 + 1] = true;
			q.push(make_tuple(c + 1, v1, v2 + 1));
		}
		if (v2 - 1 >= 0 && maze[v1][v2 - 1] == '1' && !visited[v1][v2 - 1]) {
			visited[v1][v2 - 1] = true;
			q.push(make_tuple(c + 1, v1, v2 - 1));
		}
	}
}



int main() {
	cin >> N >> M;
	vector<string>maze(N);
	vector<vector<bool>> visited(N, vector<bool>(M, false));

	for (int i = 0; i < N; i++) cin >> maze[i];

	bfs(maze, visited, 0, 0);
	
	cout << cnt;
}