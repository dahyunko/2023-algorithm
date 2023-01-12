/*047(1325)-효율적으로 해킹하기*/
#include <queue>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void bfs(vector<vector<int>>& graph, vector<char>& visited, vector<int>& rdis, int x) {
	queue <int> que;
	visited[x] = 'T';
	que.push(x);
	while (!que.empty()) {
		x = que.front();
		que.pop();
		for (int i = 0; i < graph[x].size(); i++) {
			int k = graph[x][i];
			if (visited[k] == 'F') {
				visited[k] = 'T';
				++rdis[k];//거리 추가
				que.push(k);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M;
	int max =0;

	cin >> N >> M;
	vector<vector<int>>graph;//방향그래프
	graph.resize(N + 1);
	vector<char>visited(N + 1, 'F');//방문 여부
	vector<int>rdis(N + 1, 0);//최종 거리 저장

	//그래프 생성
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >>a>>b;
		graph[a].push_back(b);
	}
	for (int i = 1; i <= N; i++) {
		bfs(graph, visited, rdis, i);//i를 시작노드로 방문
		for (int j = 1; j <= N; j++) {
			if (max < rdis[j]) max = rdis[j];//최대값 갱신
		}
		fill(visited.begin(), visited.end(), 'F');//visited 초기화
	}

	for (int i = 1; i <= N; i++) {
		if (max == rdis[i]) {
			cout << i << ' ';
		}
	}
}