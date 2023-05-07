/*1043*/
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<cmath>
#include<tuple>

using namespace std;

int parent[51];

int find(int a) {
	if (a == parent[a]) return a;
	return parent[a] = find(parent[a]);
}

void Union(int a, int b) {
	a = find(a);
	b = find(b);

	if (a != b)parent[b] = a;
}

int main() {
	int N, M;
	cin >> N >> M;

	for (int i = 1; i <= N; i++) parent[i] = i;
	vector<vector<int>>party(M);
	vector<bool> truth(N + 1, false);

	int truth_cnt;
	cin >> truth_cnt;
	for (int i = 0; i < truth_cnt; i++) {
		int now;
		cin >> now;

		truth[now] = true;
	}

	for (int i = 0; i < M; i++) {
		int people;
		cin >> people;
		for (int j = 0; j < people; j++) {
			int now;
			cin >> now;
			party[i].push_back(now);
		}
	}

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < party[i].size()-1; j++) {
			int a = find(party[i][j]);
			int b = find(party[i][j+1]);

			Union(a, b);
			if (truth[a] || truth[b]) truth[a] = true;
		}
	}

	int cnt = 0;
	for (int i = 0; i < M; i++) {
		bool flag = false;
		for (int j = 0; j < party[i].size(); j++) {
			int a = party[i][j];
			if (truth[find(a)]) flag = true;
		}
		if (!flag) cnt++;
	}

	cout << cnt;
}