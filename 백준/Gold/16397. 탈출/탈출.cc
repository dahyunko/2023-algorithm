/*19*/
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include <queue>
#include <cmath>

using namespace std;

struct info { int n, cnt; };
int N, T, G;
bool visited[100000] = { false };

int main() {
	cin >> N >> T >> G;

	int ans = -1;
	queue<info>q;
	q.push({N, 0});
	while (!q.empty()) {
		info v = q.front();
		q.pop();

		if (v.cnt > T) break;
		if (v.n == G) {
			ans = v.cnt;
			break;
		}

		if (visited[v.n])continue;
		visited[v.n] = true;

		//버튼 A
		if (v.n + 1 >= 0 && v.n + 1 < 100000) q.push({ v.n + 1, v.cnt + 1 });
		//버튼 B
		if (v.n * 2 >= 0 && v.n * 2 < 100000) {
			v.n *= 2;
			if (v.n * 2 != 0) {
				int temp = v.n, c = 0;
				while (temp > 0) {
					c++;
					temp /= 10;
				}
				v.n -= pow(10, c - 1);
			}

			q.push({ v.n, v.cnt + 1 });
		}
	}
	if (ans != -1) cout << ans;
	else cout << "ANG";
}