/*1948- 임계경로*/
#include<queue>
#include <iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<string>

using namespace std;

typedef pair<int, int> edge;

int main() {
	int N, M;
	cin >> N;
	cin >> M;

	vector<vector<edge>> graph(N + 1);
	vector<vector<edge>> rgraph(N + 1);
	vector<int> D(N + 1, 0);//진입차수
	vector<int> result(N+1, 0);//진입차수
	queue<int>q;

	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a].push_back(edge(b, c));
		rgraph[b].push_back(edge(a, c));
		D[b]++;//진입차수
	}

	int start, end;
	cin >> start >> end;
	//위상정렬
	q.push(start);
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		for (int i = 0; i < graph[v].size(); i++) {
			edge t = graph[v][i];
			D[t.first]--;
			//최대값 탐색
			if (result[t.first] < result[v] + t.second) {
				result[t.first] = result[v] + t.second;
			}
			if (D[t.first] == 0) q.push(t.first);
		}
	}
	cout << result[end] << '\n';
	
	//역 탐색
	vector<bool> visited(N + 1, false);
	q.push(end);
	int cnt = 0;
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		for (int i = 0; i < rgraph[v].size(); i++) {
			edge t = rgraph[v][i];
			
			if (result[t.first] + t.second == result[v] ) {
				cnt++;

				//재방문 방지
				if (visited[t.first] == false) {
					visited[t.first] = true;
					q.push(t.first);
				}
			}
		}
	}
	cout << cnt << '\n';
}