/*10868*/
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<stack>
#include<cmath>
#include<tuple>
#include<limits.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M;
	cin >> N >> M;

	int tree_dep = 0;
	int n = N;
	while (n != 0) {
		tree_dep++;
		n /= 2;
	}

	int tree_size = pow(2, tree_dep + 1);
	vector<int>tree(tree_size + 1, INT_MAX);
	int t = pow(2, tree_dep);

	for (int i = 0; i < N; i++) cin >> tree[t + i];

	t--;
	while (t > 0) {
		tree[t] = min(tree[t * 2], tree[t * 2 + 1]);
		t--;
	}

	for (int i = 0; i < M; i++) {
		int a, b, ans = INT_MAX;
		cin >> a >> b;

		a = a + pow(2, tree_dep) - 1;
		b = b + pow(2, tree_dep) - 1;

		while (a <= b) {
			if (a % 2 == 1) { ans = min(ans, tree[a]); a++; }
			if (b % 2 == 0) { ans = min(ans, tree[b]); b--; }

			a /= 2;
			b /= 2;
		}

		cout << ans << '\n';
	}
}