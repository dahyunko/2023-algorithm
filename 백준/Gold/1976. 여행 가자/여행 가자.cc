/*1976- 여행 계획*/
//union-find
#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
#include<vector>

using namespace std;

int find(int a, vector<int>& parent) {
	if (parent[a] == a) return a;
	return parent[a] = find(parent[a], parent);
}

void Union(int a, int b, vector<int> & parent) {
	a = find(a, parent);
	b = find(b, parent);
	
	if (a != b) parent[b] = a;
}

int main() {
	int N, M;
	cin >> N >> M;

	vector<int> parent(N + 1);
	vector<int> visit(M, 0);

	for (int i = 1; i <= N; i++) parent[i] = i;

	//도시들 연결
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int now;
			cin >> now;
			if (now == 1 && j > i) {
				Union(i, j, parent);
			}
		}
	}

	//방문 도시
	for (int i = 0; i < M; i++) cin >> visit[i];

	//방문 여부
	int flag = 0;
	for (int i = 0; i < M-1; i++) {
		int a = visit[i];
		int b = visit[i+1];
		a = find(a, parent);
		b = find(b, parent);
		if (a != b) flag++;
	}

	if (flag > 0) cout << "NO";
	else cout << "YES";
}