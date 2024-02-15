/*17471*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <sstream>
#include <limits.h>
using namespace std;

int N, sum = 0, result = INT_MAX;
int a_sum, b_sum;
int people[11];
vector<vector<int>> graph;
int list[11];
vector<int> a_load, b_load;

bool check_num(vector<int> path, int now) {
	for (int i = 0; i < path.size(); i++) {
		if (path[i] == now) return true;
	}
	return false;
}

bool has_path(vector<int> path) {
	vector<bool>visited(N, false);
	int temp = 0;

	queue<int>q;
	q.push(path[0]);

	while (!q.empty()) {
		int v = q.front();
		q.pop();

		if (visited[v]) continue;
		visited[v] = true;
		temp++;

		for (int i = 0; i < graph[v].size(); i++) {
			int next = graph[v][i];
			if (check_num(path, next) && !visited[next]) {
				q.push(next);
			}
		}
	}

	if (temp == path.size()) return true;
	return false;
}

void find_section(int cnt, int C, int j) {
	if (cnt == C) {
		a_load.clear();
		b_load.clear();
		a_sum = 0;
		b_sum = 0;
		vector<bool>visited(N, false);

		// 도시 2개 생성
		for (int i = 0; i < cnt; i++) {
			a_load.push_back(list[i]);
			visited[list[i]] = true;
			a_sum += people[list[i]];
		}

		for (int i = 0; i < N; i++) {
			if (visited[i]) continue;
			b_load.push_back(i);
			b_sum += people[i];
		}

		if (!has_path(a_load) || !has_path(b_load)) return;
		result = min(result, abs(a_sum - b_sum));
		return;
	}

	for (int i = j; i < N; i++) {
		list[cnt] = i;
		find_section(cnt + 1, C, i + 1);
	}
}

int main() {
	cin >> N;
	graph.resize(N);

	// 인구 받기
	for (int i = 0; i < N; i++) {
		cin >> people[i];
		sum += people[i];
	}
	
	// 그래프 생성
	for (int i = 0; i < N; i++) {
		int cnt;
		cin >> cnt;
		for (int j = 0; j < cnt; j++) {
			int now;
			cin >> now;

			graph[i].push_back(now - 1);
		}
	}

	// 지역 분리
	for (int i = 1; i <= N / 2; i++) {
		find_section(0, i, 0);
	}

	if (result != INT_MAX) cout << result;
	else cout << -1;
}