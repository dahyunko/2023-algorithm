/*072(10868)- 최솟값 찾기2*/
//빈곳에 max값을 넣어줘야함
#include<cmath>
#include<limits.h>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

void part_min(vector<long> &tree, int start, int end) {
	long min_value = LONG_MAX;
	while (start <= end) {
		if (start % 2 == 1) {
			min_value = min(min_value, tree[start]);
			start++;
		}
		if (end % 2 == 0) {
			min_value = min(min_value, tree[end]);
			end--;
		}
		start /= 2;
		end /= 2;
	}

	cout << min_value << '\n';
}

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M;
	cin >> N >> M;

	int length = N;
	int tree_length = 0;
	while (length != 0) {
		length /= 2;
		tree_length++;
	}
	//최소 트리 생성
	int tree_size = pow(2, tree_length + 1);
	vector<long> tree(tree_size + 1, LONG_MAX);
	int t = pow(2, tree_length);
	for (int i = 0; i < N; i++) {
		cin >> tree[t + i];
	}
	t--;
	while (t > 0) {//최솟값 삽입
		tree[t] = min (tree[t * 2], tree[2 * t + 1]);
		t--;
	}

	//구간 최솟값
	for (int i = 0; i < M; i++) {
		long a, b;
		cin >> a >> b;
		a = pow(2, tree_length) + a - 1;
		b = pow(2, tree_length) + b - 1;
		part_min(tree, a, b);
	}
}