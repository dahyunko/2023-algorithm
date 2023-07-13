/*17484*/
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<sstream>
#include<limits.h>
#include<tuple>

using namespace std;

int A[7][7];
int N, M, d, result;

//direct : 1, 2, 3
void find_path(int now, int direct, int loc, int cnt) {
	if (cnt == N) { 
		result = min(now, result);
		return; 
	}

	if (direct != 1 && loc - 1 >= 0) {
		find_path(now + A[cnt][loc - 1], 1, loc - 1, cnt + 1);
	}
	if (direct != 2) {
		find_path(now + A[cnt][loc], 2, loc, cnt + 1);
	}
	if (direct != 3 && loc + 1 < M) {
		find_path(now + A[cnt][loc + 1], 3, loc + 1, cnt + 1);
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) cin >> A[i][j]; 
	}

	int ans = INT_MAX;
	for (int t = 0; t < M; t++) {
		result = INT_MAX;
		d = A[0][t];
		find_path(d, 0, t, 1);

		ans = min(ans, result);
	}

	cout << ans;
}