/*067(11725)- 트리의 부모 찾기*/
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

void Dfs_tree(vector<vector<int>>& tree, vector<char>& visited, vector<int>& parent, int v) {
	visited[v] = 'T';

	for (int i = 0; i < tree[v].size(); i++) {
		int t = tree[v][i];

		if (visited[t] == 'F') {
			parent[t] = v;
			Dfs_tree(tree, visited, parent, t);
		}
	}
}

int main() {
	int N;

	cin >> N;
	vector<vector<int>> tree;
	tree.resize(N + 1);
	vector<char> visited(N + 1, 'F');
	vector<int> parent(N + 1, 0);

	//트리 생성
	for (int i = 0; i < N-1; i++) {
		int a, b;
		cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}

	Dfs_tree(tree, visited, parent, 1);
	//root노드 1로 가정

	for (int i = 2; i <= N; i++) {
		cout << parent[i] << '\n';
	}
}