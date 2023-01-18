/*068(1068)- 리프 노드의 개수 구하기*/
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

typedef pair<char, char> info;

void Bfs_tree(vector<vector<int>> &tree, vector<info> &visited, int v) {
	visited[v].first = 'T';
	int v_count = 0;

	for (int i = 0; i < tree[v].size(); i++) {
		int t = tree[v][i];

		if (visited[t].first == 'F') {
			if (visited[t].second != 'B') {
				v_count++;
				Bfs_tree(tree, visited, t);
			}
		}
	}

	//리프 노드인것
	if (v_count == 0) visited[v].second = 'G';
}

int main() {
	int N, remove_n, root;

	cin >> N;
	vector<vector<int>> tree;
	tree.resize(N);
	vector<int> parent(N);
	vector <info> visited(N, info('F','W'));
	//처음: white, 리프: Green, 삭제: B
	
	//부모 노드 저장 & 트리 생성
	for (int i = 0; i < N; i++) {
		int now;
		cin >> now;
		parent[i] = now;
		if (now != -1) {
			tree[i].push_back(now);
			tree[now].push_back(i);
		}
		else {
			root = i;
		}
	}

	//지울 노드
	cin >> remove_n;
	visited[remove_n].second = 'B';
	if (remove_n == root) {//루트 노드를 지우면 트리 삭제 되는것
		cout << 0;
	}
	else {
		//리프 탐색
		Bfs_tree(tree, visited, root);
		int count = 0;
		for (int i = 0; i < N; i++) {
			if (visited[i].second == 'G') count++;
		}
		cout << count;
	}
}