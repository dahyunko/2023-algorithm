/*20922*/
#include <iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<limits.h>
#include<map>
#include<set>
#include<queue>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N, K;
	cin >> N >> K;

	map<int, int>m;
	vector<int>A(N);
	for (int i = 0; i < N; i++) cin >> A[i];

	int s = 0, e = 0, ans = 0;
	while (s < N) {
		while (e < N) {
			if (m[A[e]] + 1 > K)break;
			m[A[e++]]++;
		}

		ans = max(ans, e - s);
		m[A[s++]]--;
	}

	cout << ans;
}