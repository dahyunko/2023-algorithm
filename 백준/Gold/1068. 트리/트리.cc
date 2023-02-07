/*1068- 트리*/
//dfs
#include <iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<string>

using namespace std;

void dfs(vector<vector<int>> &graph, vector<char> &visited, vector<char>& color, int v){
	if (visited[v] == 'T' || color[v] == 'B')return;
	visited[v] = 'T';
	
	int flag = 0;
	for (int i = 0; i < graph[v].size(); i++) {
		int t = graph[v][i];
		if (visited[t] == 'F' && color[t] != 'B') {
			flag = 1;
			dfs(graph, visited, color, t);
		}
	}

	if (flag == 0) color[v] = 'G';
}

int main() {
	int N;
		
	cin >> N;
	vector<vector<int>> graph(N + 1);
	vector<char> visited(N + 1, 'F');
	vector<char> color(N + 1, 'W');//white(부모), green(리프), black(삭제)
	int root;

	for (int i = 0; i < N; i++) {
		int now;
		cin >> now;
		if (now == -1) root = i;
		else graph[now].push_back(i);
	}
	int delete_node;
	cin >> delete_node;
	color[delete_node] = 'B';
	dfs(graph, visited, color, root);

	int cnt = 0;
	for (int i = 0; i < N; i++) {
		if (color[i] == 'G') cnt++;
	}
	cout << cnt;
}