/*071(2042)- 구간합 구하기*/
//세그먼트 트리: 주어진 데이터 구간 합과 데이터 업데이트를 빠르게 수행
//구간합, 최대, 최소, 데이터 업데이트
#include <cmath>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;


void change(vector<long>& tree, int index, long num) {
	tree[index] = num;
	index /= 2;
	while (index != 0) {
		tree[index] = tree[index * 2] + tree[index * 2 + 1];
		index /= 2;
	}
}

void interval_add(vector<long>& tree, int start, int end) {
	long result = 0;
	while (start <= end) {
		if (start % 2 == 1){ 
			result += tree[start];
			start++; 
		}
		if (end % 2 == 0) {
			result += tree[end];
			end--;
		}
		start /= 2;
		end /= 2;
	}

	cout << result << '\n';
}

int main() {
	int N, M, K;
	
	cin >> N >> M >> K;

	int length = N;
	int tree_height = 0;//트리 노드 개수
	while (length != 0) {
		length /= 2;
		tree_height++;
	}

	//트리 생성
	int tree_size = 0;
	tree_size = pow(2, tree_height + 1);//2^k*2, pow: 제곱근
	vector<long> tree(tree_size + 1, 0);
	int t;//트리에 들어가는 순서
	t = pow(2, tree_height);
	for (int i = 0; i < N; i++) {
		cin >> tree[t + i];
	}
	t--;
	while (t > 0) {
		tree[t] = tree[2 * t] + tree[2 * t + 1];
		t--;
	}

	for (int i = 0; i < M + K; i++) {
		long a, b, c;
		cin >> a >> b >> c;
		if (a == 1) {//index변경
			b = pow(2, tree_height) + b - 1;
			change(tree, b, c);
		}
		else {//구간합 출력
			b = pow(2, tree_height) + b - 1;
			c = pow(2, tree_height) + c - 1;
			interval_add(tree, b, c);
		}
	}
}