/*1138*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;

int N;
int list[11];
int A[11];
bool visited[11] = { false };

void dfs(int cnt) {
	if (cnt == N) {
		for (int i = 0; i < N; i++) {
			int count = 0;

			for (int j = 0; j < i; j++) {
				if (list[j] > list[i]) count++;
			}
			if (count != A[list[i]]) return;
		}

		for (int i = 0; i < N; i++) cout << list[i] + 1 << ' ';
		return;
	}

	for (int i = 0; i < N; i++) {
		if (visited[i]) continue;
		visited[i] = true;
		list[cnt] = i;
		dfs(cnt + 1);
		visited[i] = false;
	}
}

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) cin >> A[i];	
	dfs(0);
}