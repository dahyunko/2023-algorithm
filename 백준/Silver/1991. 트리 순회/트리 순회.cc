/*1991- 중위, 후위, 전위 순회*/
#include <iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<string>

using namespace std;

int tree[27][2]={-1};

void preorder(int v) {
	char now = 'A' + v -1 ;
	cout << now;
	if (tree[v][0] != 0) preorder(tree[v][0]); 
	if (tree[v][1] != 0) preorder(tree[v][1]); 
}

void inorder(int v) {
	if (tree[v][0] != 0) inorder(tree[v][0]);
	char now = 'A' + v -1;
	cout << now;
	if (tree[v][1] != 0) inorder(tree[v][1]);
}

void postorder(int v){
	if (tree[v][0] != 0) postorder(tree[v][0]);
	if (tree[v][1] != 0) postorder(tree[v][1]);
	char now = 'A' + v -1;
	cout << now;
}

int main() {
	int N;

	cin >> N;
	for (int i = 0; i < N; i++) {
		char a, b, c;
		cin >> a >> b >> c;

		int now = a - 'A' + 1;
		if (b != '.') tree[now][0] = b - 'A' + 1;
		if (c != '.') tree[now][1] = c - 'A' + 1;
	}

	preorder(1);
	cout << '\n';
	inorder(1);
	cout << '\n';
	postorder(1);
}