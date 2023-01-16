/*059(11657)- 타임머신*/
//벨만포드: 음수 사이클 찾는 것, 음수 weight 존재 하는 경우
#include<limits.h>
#include <tuple>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;
typedef tuple<int, int, int> Edge;

int main() {
	int N, M;

	cin >> N >> M;

	vector<Edge> edges;
	vector<long> D(N + 1, LONG_MAX);//정답 배열

	for (int i = 0; i < M; i++) {
		int A, B, C;
        cin >> A >> B >> C;
		edges.push_back(Edge(A, B, C));
		//시작점, 끝점, 가중치
	}

	//벨만 포드
	D[1] = 0;
	for (int i = 1; i < N; i++) {//N-1번 반복
		for (int j = 0; j < edges.size() ; j++) {
			Edge medge = edges[j];
			int start = get<0>(medge);
			int end = get<1>(medge);
			int time = get<2>(medge);

			//최단 거리 갱신
			if (D[start] != LONG_MAX && D[end] > D[start] + time) {
				D[end] = D[start] + time;
			}
		}
	}

	//음수 사이클 확인
	bool mcycle = false;
	for (int i = 0; i < edges.size(); i++) {
		Edge medge = edges[i];
		int start = get<0>(medge);
		int end = get<1>(medge);
		int time = get<2>(medge);

		if (D[start] != LONG_MAX && D[end] > D[start] + time) {
			mcycle = true;
		}
	}

	if (!mcycle) {//음수 사이클 아닐 경우
		for (int i = 2; i <= N; i++) {
			if (D[i] == LONG_MAX) cout << -1 << '\n';
			else cout << D[i] << '\n';
		}
	}
	else {
		cout << -1 << '\n';
	}
}