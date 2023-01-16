/*060(1219)- 세일즈맨의 고민*/
//그래프 + 가중치(양수, 음수)=> 벨만 포드
#include <tuple>
#include <limits.h>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;
typedef tuple<int, int, int> Edge;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, s, e, M;
	cin >> N >> s >> e >> M;
	
	vector<Edge> edges;
	vector<int> earn(N + 1, 0);
	vector<long> D(N+1,LONG_MIN);

	//간선 생성
	for (int i = 0; i < M; i++) {
		int start, end, money;
		cin >> start >> end >> money;
		edges.push_back(Edge(start, end, money));
	}
	//벌 수 있는 돈
	for (int i = 0; i < N; i++) {
		cin >> earn[i];
	}

	D[s] = earn[s];
	for (int i = 0; i < N+50; i++) {
		for (int j = 0; j < edges.size(); j++) {
			int start = get<0>(edges[j]);
			int end = get<1>(edges[j]);
			int money = get<2>(edges[j]);

			if (D[start] != LONG_MIN && D[end] < D[start]+earn[end] - money) {
				D[end] = D[start] + earn[end] - money;
				if (i >= N + 1) {
					//N+1번 이후 갱신되는 노드는 양수 사이클 연결 노드로 변경
					D[end] = LONG_MAX;
				}
			}
			else if (D[start] == LONG_MAX) {
				//시작 노드가 LONG_MAX일 경우 끝노드도 LONG_MAX
				D[end] = LONG_MAX;
			}
		}
	}

	if (D[e] == LONG_MIN) {
		cout << "gg";//도착 못함
	}
	else if (D[e] == LONG_MAX) {
		cout << "Gee";//양수 사이클
	}
	else {
		cout << D[e];//그 외의 경우
	}

}