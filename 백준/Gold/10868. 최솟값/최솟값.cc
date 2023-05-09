/*10868*/
#include <iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<string>
#include<limits.h>

using namespace std;

long findmin(long left, long right, vector<long>& tree) {
	long result = LONG_MAX;

	while (left <= right) {
		if (left % 2 == 1) {
			result = min(result, tree[left]);
			left++;
		}
		if (right % 2 == 0) {
			result = min(result, tree[right]);
			right--;
		}
		left /= 2;
		right /= 2;
	}
	return result;
}

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

	long tree_size = pow(2, tree_dep+1);
	vector<long> tree(tree_size + 1, LONG_MAX);
	long t = tree_size / 2;

	for (int i = t; i < t + N; i++) cin >> tree[i];
	t--;
	//정렬
	while (t > 0) {
		tree[t] = min(tree[t * 2], tree[t * 2 + 1]);
		t--;
	}

	for (int i = 0; i < M; i++) {
		long a, b;
		cin >> a >> b;
		a = pow(2, tree_dep) + a - 1;
		b = pow(2, tree_dep) + b - 1;

		cout<< findmin(a, b ,tree)<<'\n';
	}
}