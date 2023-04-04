/*A->B -16953*/
#include<queue>
#include <iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<string>

using namespace std;

long cnt = -1;

void dfs(long a, long b, long c) {
	if (a == b) {
		if (cnt == -1) cnt = c;
		else cnt = min(c, cnt);
		return;
	}
	if (a > b) return;

	dfs(a * 2, b, c+1);
	dfs(a * 10 + 1, b, c+1);
}

int main() {
	long A, B;

	cin >> A >> B;

	dfs(A, B, 1);

	cout << cnt;
}