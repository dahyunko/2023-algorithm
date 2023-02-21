/*1697*/
#include<limits.h>
#include<queue>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

typedef pair<int, int> info;

int N, K;
int t = INT_MAX;
bool visited[200001] = {false};

void bfs(int x, int cnt) {
	queue<info> q;
	
	visited[x] = true;
	q.push(info(cnt, x));

	while (!q.empty()) {
		cnt = q.front().first;
		x = q.front().second;
		q.pop();

		if (x == K) {
			t = min(t, cnt);
			break;
		}

		if (x*2 < K*2 && !visited[x * 2] ) { 
			visited[x * 2] = true;  q.push(info(cnt + 1, x * 2)); 
		}
		if (x - 1 >= 0 && !visited[x - 1]) {
			visited[x - 1] = true;
			q.push(info(cnt + 1, x - 1));
		}
		if (!visited[x + 1] && x + 1 <= K) { 
			visited[x + 1] = true;
			q.push(info(cnt + 1, x + 1));
		}
	}
	
}

int main() {
	cin >> N >> K;

	bfs(N, 0);
	cout << t;
}