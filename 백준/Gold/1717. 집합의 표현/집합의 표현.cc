/*050(1717)- 집합의 표현*/
#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
#include<vector>

using namespace std;

int find(vector<int>& A, int a) {
	if (a == A[a]) return a;
	return A[a] = find(A, A[a]);
}

void Union(vector<int>& A, int a, int b) {
	a = find(A, a);
	b = find(A, b);
	if (a != b) A[b] = a;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M;

	cin >> N >> M;
	vector<int>parent(N + 1);
	
	//대표 노드 설정
	for (int i = 0; i <= N; i++) parent[i] = i;

	for (int j = 0; j < M; j++) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 0) {//union
			Union(parent, b, c);
		}
		else {
			b = find(parent, b);
			c = find(parent, c);
			if (b == c) cout << "YES\n";
			else cout << "NO\n";
		}
	}
}