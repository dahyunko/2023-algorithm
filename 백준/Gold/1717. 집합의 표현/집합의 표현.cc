/*050(1717)-집합 표현하기*/
//union-find: 
//union: 특정 2개의 노드를 연결해 1개의 집합
//find: 두노드가 같은 집합에 속해 있는지 확인
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int g_find(int a, vector<int>& parent) {
	if (a == parent[a]) return a;
	else return parent[a] = g_find(parent[a], parent);
}

void g_union(int a, int b, vector<int>& parent) {
	a = g_find(a, parent);
	b = g_find(b, parent);

	if (a != b) parent[b] = a;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;

	cin >> n >> m;
	vector<int> parent(n + 1);

	//대표 노드를 자신으로 초기화
	for (int i = 0; i <= n; i++) parent[i] = i;

	for (int i = 0; i < m; i++) {
		int c, a, b, result;
		cin >> c >> a >> b;
		
		if (c == 0) {//union
			g_union(a, b, parent);
		}
		else {//find
			if (g_find(a, parent) == g_find(b, parent)) cout << "YES" << '\n';
			else cout << "NO" << '\n';
		}
	}
}