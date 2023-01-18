/*070(1991)- 트리 순회하기*/
//이진 트리
//전위 순회한 결과 : ABDCEFG // (루트) (왼쪽 자식) (오른쪽 자식)
//중위 순회한 결과 : DBAECFG // (왼쪽 자식) (루트) (오른쪽 자식)
//후위 순회한 결과 : DBEGFCA // (왼쪽 자식) (오른쪽 자식) (루트)
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

typedef pair<char, char> info;

void pre_order(vector<info> tree, char v) {
	int t = v - 'A';

	cout << v;//루트 출력
	if (tree[t].first != '.') {//왼쪽
		pre_order(tree, tree[t].first);
	}
	if (tree[t].second != '.') {//오른쪽
		pre_order(tree, tree[t].second);
	}
}

void mid_order(vector<info> tree, char v) {
	int t = v - 'A';

	if (tree[t].first != '.') {
		mid_order(tree, tree[t].first);
	}
	cout << v;//출력
	if (tree[t].second != '.') {
		mid_order(tree, tree[t].second);
	}
}

void last_order(vector<info> tree, char v) {
	int t = v - 'A';

	if (tree[t].first != '.') {
		last_order(tree, tree[t].first);
	}
	if (tree[t].second != '.') {
		last_order(tree, tree[t].second);
	}
	cout << v;//출력
}

int main() {
	int N;//노드 개수

	cin >> N;
	vector<info> tree;
	tree.resize(N);
	for (int i = 0; i < N; i++) {
		char a, b, c;
		int t;
		cin >> a >> b >> c;
		t = a - 'A';
		//first: left, second: right
		tree[t].first = b;
		tree[t].second = c;
	}

	//전위 순회
	pre_order(tree, 'A');
	cout << '\n';
	//중위 순회
	mid_order(tree, 'A');
	cout << '\n';
	//후위 순회
	last_order(tree, 'A');
}