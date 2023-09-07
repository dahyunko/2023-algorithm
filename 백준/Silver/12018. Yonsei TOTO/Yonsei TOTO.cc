#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include <queue>
#include<stack>
#include <cmath>
#include<limits.h>
#include<set>
#include<map>

using namespace std;

bool cmp(int a, int b) { return a > b; }

int main() {
	int N, M;
	cin >> N >> M;
	vector<int>ans(N);

	for (int i = 0; i < N; i++) {
		int A, B;
		cin >> A >> B;
		
		vector<int>D(A);
		for (int a = 0; a < A; a++) cin >> D[a];
		sort(D.begin(), D.end(), cmp);

		if (A < B) {
			ans[i] = 1;
			continue;
		}
		ans[i] = D[B-1];
	}
	sort(ans.begin(), ans.end());

	int result = 0, cnt = 0;
	for (int i = 0; i < N; i++) {
		//cout << ans[i] << '\n';
		if (result + ans[i] > M)continue;
		result += ans[i];
		cnt++;
	}
	cout << cnt;
}