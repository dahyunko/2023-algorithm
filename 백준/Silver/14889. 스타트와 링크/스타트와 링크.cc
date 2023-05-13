#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<stack>
#include<cmath>
#include<tuple>
#include<limits.h>

using namespace std;

int Field[21][21];
vector<int> list(11);
int gap = INT_MAX;
int N;
bool visited[21] = { false };

void dfs(int cnt, int j) {
	if (cnt == N/2) {

		int start = 0, link = 0;
		vector<int>links;
		for (int i = 0; i < N; i++) {
			if (find(list.begin(), list.begin()+N/2, i) == list.begin() + N / 2) links.push_back(i);
		}

		for (int i = 0; i < N / 2; i++) {
			for (int j = 0; j < N / 2 ; j++) {
				if (i == j) continue;
				start += Field[list[i]][list[j]];
			}
		}

		for (int i = 0; i < N / 2; i++) {
			for (int j = 0; j < N / 2; j++) {
				if (i == j) continue;
				link += Field[links[i]][links[j]];
			}
		}

		gap = min(gap, abs(start - link));

		return;
	}

	for (int i = j; i < N; i++) {
		list[cnt] = i;
		dfs(cnt + 1, i+1);
	}
}

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) cin >> Field[i][j];
	}

	dfs(0, 0);

	cout << gap;
}