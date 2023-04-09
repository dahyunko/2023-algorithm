/*이모티콘- 14226*/
#include<tuple>;
#include<queue>
#include <iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<string>
#include <limits.h>

using namespace std;

typedef tuple<int, int, int> info;

int main() {
	int S, time= INT_MAX;
	bool visited[1001][1001] = { false };

	cin >> S;

	queue<info>q;
	q.push(make_tuple(1, 0, 0));
	visited[1][0] = true;

	while (!q.empty()) {
		info v = q.front();
		int c = get<0>(v);
		int t = get<1>(v);
		int b = get<2>(v);

		q.pop();

		if (c == S) {time = t;break;}

		if (c < 0 || c>1001) continue;
		if (!visited[c][c]) {
			visited[c][c] = true;
			q.push(make_tuple(c, t + 1, c)); 
		}
		if (b > 0 && c + b < 1001 && !visited[c + b][b]) {
			visited[c + b][b] = true;
			q.push(make_tuple(c + b, t + 1, b));
		}
		if (!visited[c - 1][b]) {
			visited[c - 1][b] = true;
			q.push(make_tuple(c - 1, t + 1, b));
		}
	}
	cout << time;
}