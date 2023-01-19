/*073(11505)- 구간 곱 구하기*/
//이진트리
#include <cmath>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;
static int Mod = 1000000007;

void change(vector<long long>& tree, int index, long long num) {
	tree[index] = num;
	index /= 2;
	while (index != 0) {
		long long left, right;
		left = tree[index * 2] % Mod;
		right = tree[index * 2 + 1] % Mod;
		tree[index] = (left * right) % Mod;
		index /= 2;
	}
}

//구간 곱
long long part_mul(vector<long long> & tree, int start, int end) {
	long long result = 1;
	while (start <= end) {
		if (start % 2 == 1) {
			result = result * tree[start] % Mod;
			start++;
		}
		if (end % 2 == 0) {
			result = result * tree[end] % Mod;
			end--;
		}
		start /= 2;
		end /= 2;
	}

	return result % Mod;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M, K;

	cin >> N >> M >> K;

	int length = N;
	int length_tree = 0;
	while (length != 0) {
		length /= 2;
		length_tree++;
	}
	//트리 생성
	int tree_size = pow(2, length_tree + 1);//트리 사이즈 2^(k+1)
	vector<long long> tree(tree_size+1, 0);
	int t = pow(2, length_tree);//트리 생성 index
	for (int i = 0; i < N; i++) {
		cin >> tree[t + i];
	}
	t--;
	while (t > 0) {
		tree[t] = tree[t * 2] % Mod * tree[t * 2 + 1] % Mod;
		t--;
	}

	//변경 + 구간 곱
	for (int i = 0; i < K + M; i++) {
		long long a, b, c;
		cin >> a >> b >> c;
		if (a == 1) {//변경
			b = pow(2, length_tree) + b - 1;
			change(tree, b, c);
		}
		else {//곱
			b = pow(2, length_tree) + b - 1;
			c = pow(2, length_tree) + c - 1;
			
			cout << part_mul(tree, b, c) << '\n';
		}
	}
}