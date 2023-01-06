/*023- 연결 요소의 개수 구하기
*DFS(깊이 우선 탐색): stack or 재귀함수 이용
*/

//재귀 이용의 경우
#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<vector<int>>&graph, vector<char> &visited, int first) {
	if (visited[first] == 'T') return; //방문 했을 시 return
	
	visited[first] = 'T';//방문
	//cout << first << '\n';

	for (int i = 0; i < graph[first].size(); i++) {
		int j = graph[first][i];
		if (visited[j] == 'F') {
			dfs(graph, visited, j);
		}
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
	int N, M;//정점,  간선
	int count = 0;

	cin >> N >> M;

	vector<vector<int>>graph;
	graph.resize(N + 1);
	vector<char> visited(N+1,'F');

	//그래프 생성
	for (int i = 1; i <= M; i++) {
		int a, b;
		cin >> a >> b;

		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	
	for (int i = 1; i <= N; i++) {
		if (visited[i] == 'F') {
			count++;
			dfs(graph, visited, i);
		}
	}

	cout << count << '\n';
}