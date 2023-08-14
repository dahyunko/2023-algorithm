#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include <queue>
#include <cmath>
#include<limits.h>
#include<set>

using namespace std;

int N;
int A[101] = { 0 };
vector<bool> visited(101, false);
set<int> s;
bool isRight = false;

void dfs(int firstNum, int num) {
	if (visited[num]) {
		if (firstNum == num) {
			isRight = true;
			s.insert(num);
		}
		return;
	}
	visited[num] = true;
	dfs(firstNum, A[num]);
	if (isRight) {
		s.insert(num);
		s.insert(A[num]);
	}
}

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> A[i];

	for (int t = 1; t <= N; t++) {
		visited[t] = true;
		dfs(t, A[t]);
		fill(visited.begin(), visited.end(), false);
		isRight = false;
	}

	cout << s.size() << '\n';
	for (auto it : s) cout << it << '\n';
}