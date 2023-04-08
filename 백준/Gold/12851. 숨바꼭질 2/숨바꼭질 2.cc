#include<queue>
#include <iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<string>
#include<limits.h>

using namespace std;

typedef pair<long, long> info;

int main() {
	long N, K, cnt = LONG_MAX, way = 0;

	cin >> N >> K;

	bool dp[200001] = {false};
	queue<info>q;
	q.push(info(N, 0));

	while (!q.empty()) {
		info v = q.front();
		long n = v.first;
		long c = v.second;

		q.pop();
		if (n == K) {
			if (cnt == c) way++;
			else if (cnt > c) {
				cnt = c;
				way++;
			}
			continue;
		}

		dp[n] = true;
		if (n < 100000 && !dp[n*2]) q.push(info(n * 2, c + 1));
		if (n - 1 >= 0 && !dp[n-1]) q.push(info(n - 1, c + 1));
		if (n + 1 <= K && !dp[n+1]) q.push(info(n + 1, c + 1));
	}

	cout << cnt << '\n';
	cout << way << '\n';
}