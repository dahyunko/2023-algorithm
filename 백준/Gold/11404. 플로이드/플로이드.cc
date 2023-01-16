#include <limits.h>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio;
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M;
	int D[101][101];

	cin >> N;
	cin >> M;

	//최단 거리 배열
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i == j) {
				D[i][j] = 0;
			}
			else D[i][j] = INT_MAX/2;
		}
	}
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		if (D[a][b] > c) {
			D[a][b] = c;
		}
	}

	for (int k = 1; k <= N; k++) {//경유지 k
		for (int s = 1; s <= N; s++) {//출발노드 s
			for (int e = 1; e <= N; e++) {// 도착노드 e
				//점화식 배열 업데이트
				D[s][e] = min(D[s][e], D[s][k] + D[k][e]);
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (D[i][j] == INT_MAX / 2) cout << "0 ";//길없음
			else cout << D[i][j] << ' ';
		}
		cout << '\n';
	}
}