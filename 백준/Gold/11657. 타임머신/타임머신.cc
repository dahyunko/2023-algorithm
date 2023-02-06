/*11657- 타임머신*/
//벨만 포드: tuple, 엣지 중심으로 탐색
#include <limits.h>
#include <tuple>
#include <iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<string>

using namespace std;

typedef tuple<int, int, int> edge;

int main() {
	int N, M;

	cin >> N >> M;
	vector<edge> edges;
	vector<long> D(N + 1, LONG_MAX);

	//엣지 생성
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;

		edges.push_back(make_tuple(a, b, c));
	}

	//벨만 포드
	D[1] = 0;
	for (int i = 0; i < N - 1; i++) {
		for (int j = 0; j < M; j++) {
			int s = get<0>(edges[j]);
			int e = get<1>(edges[j]);
			int w = get<2>(edges[j]);

			//업데이트
			if (D[s] != LONG_MAX && D[e] > D[s] + w) {
				D[e] = D[s] + w;
			}
		}
	}

	//음수 사이클 확인
	bool isCycle = false;
	for (int j = 0; j < M; j++) {
		int s = get<0>(edges[j]);
		int e = get<1>(edges[j]);
		int w = get<2>(edges[j]);

		if (D[s] != LONG_MAX && D[e] > D[s] + w) {
			isCycle = true;
		}
	}

	if (isCycle) cout << -1;
	else {
		for (int i = 2; i <= N; i++) {
			if (D[i] == LONG_MAX) cout << -1 << '\n';
			else cout << D[i] << '\n';
		}
	}
}