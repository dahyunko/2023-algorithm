/*숨박꼭질3- 13549*/
#include<limits.h>
#include<queue>
#include <iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<string>

using namespace std;

typedef pair<int, int>info;

int main() {
	int N, K, ans = INT_MAX;

	cin >> N >> K;
	
	bool visited[200001] = { false };
	queue<info>q;
	q.push(info(N, 0));

	while (!q.empty()) {
		int n = q.front().first;
		int c = q.front().second;

		q.pop();

		if (n == K && ans> c) {
			ans = c;
			continue;
		}

		if (visited[n]) continue;
		visited[n] = visited;

		if (n < 100000) q.push(info(n * 2, c));
		if (n-1 >= 0) q.push(info(n - 1, c+1));
		if (n+1 <= 100000) q.push(info(n + 1, c+1));
	}

	cout << ans;
}