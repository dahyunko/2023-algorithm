#include <string>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <queue>

using namespace std;

typedef pair<int, int> edge;
int hour = INT_MAX;
bool isFin;

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    vector<int> answer;
    
    
	vector<vector<edge>> graph(n + 1);
	vector<char> info(n + 1, 'c');
	vector<int> d(n + 1, INT_MAX);
	//출구:a, 봉우리:b, 휴식:c

	for (int i = 0; i < gates.size(); i++) info[gates[i]] = 'a';
	sort(summits.begin(), summits.end());
	for (int i = 0; i < summits.size(); i++) info[summits[i]] = 'b';

	//그래프 생성
	for (int i = 0; i < paths.size(); i++) {
		int s = paths[i][0];
		int e = paths[i][1];
		int w = paths[i][2];

		graph[s].push_back(edge(w, e));
		graph[e].push_back(edge(w, s));
	}
	for (int i = 1; i <= n; i++) sort(graph[i].begin(), graph[i].end());

	int a = INT_MAX, b = INT_MAX;
	
	priority_queue<edge, vector<edge>, greater<edge>>q;

	for (int i = 0; i < gates.size(); i++) { 
		q.push(edge(0, gates[i])); 
		d[gates[i]] = 0;
	}

	while (!q.empty()) {
		edge v = q.top();
		q.pop();
		int now = v.second;
		int now_w = v.first;

		if (d[now] != now_w) continue;

		for (int i = 0; i < graph[now].size(); i++) {
			edge t = graph[now][i];
			int e = t.second;
			int w = t.first;

			if (d[e] <= max(d[now], w)) continue;
			d[e] = max(d[now], w);
			if (info[e] == 'c') q.push(edge(d[e], e));
		}
	}

	for (int i = 0; i < summits.size(); i++) {
		if (d[summits[i]] != INT_MAX) {
			if (b > d[summits[i]]) {
				b = d[summits[i]];
				a = summits[i];
			}
		}
	}

	answer.push_back(a);
	answer.push_back(b);
    
    return answer;
}