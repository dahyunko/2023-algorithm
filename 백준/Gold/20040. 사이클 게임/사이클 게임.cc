/*20040- 사이클 게임*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int parent[500001] = {0};

int find(int a) {
	if (parent[a] == a)return a;
	return parent[a] = find(parent[a]);
}

void Union(int a, int b) {
	a = find(a);
	b = find(b);
	if (a != b) parent[b] = a;
}

int main() {
	int n, m;

	cin >> n >> m;

	for (int i = 0; i < n; i++) parent[i] = i;

	int flag = 0;
	int cycle;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;

		a = find(a);
		b = find(b);
		if (a != b) {
			Union(a, b);
		}
		else { 
			flag++; 
			if (flag == 1) cycle = i + 1;
		}
	}
	if (flag > 0) cout << cycle;
	else cout << 0;
}