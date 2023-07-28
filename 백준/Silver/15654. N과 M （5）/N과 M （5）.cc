/*15654*/
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include <queue>
#include <cmath>
#include<limits.h>
#include<set>

using namespace std;

int list[9];
int A[9];
int N, M;
bool visited[9] = { false };

void dfs(int cnt) {
	if (cnt == M) {
		for (int i = 0; i < M; i++) cout << list[i] << ' ';
		cout << '\n';
		return;
	}

	for (int i = 0; i < N; i++) {
		if (visited[i])continue;
		visited[i] = true;
		list[cnt] = A[i];
		dfs(cnt + 1);
		visited[i] = false;
	}
}

int main() {
	cin >> N >> M;

	for (int i = 0; i < N; i++) cin >> A[i];
    sort(A, A + N);
	dfs(0);
}