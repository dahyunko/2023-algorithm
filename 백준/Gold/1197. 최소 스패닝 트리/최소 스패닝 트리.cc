/*064(1197)- 최소신장트리*/
//union-find 사용, 탐욕기법 사용
#include <tuple>;
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

typedef tuple<int, int, int> Edge;

int Find(int a, vector<int>& D) {
	if (D[a] == a) return a;
	else return D[a] = Find(D[a], D);
}

int Union(int a, int b, vector<int> &D) {
	a = Find(a, D);
	b = Find(b, D);

	//두 노드의 대표 노드가 같다면 사이클 형성
	//따라서 다를 때만 두 노드를 연결
	if (a != b) {
		D[b] = a;
		return 1;
	}
	else return 2;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int V, E;
	int count_edge = 0, result = 0;
	int flag;

	cin >> V >> E;
	vector<Edge> edges;
	vector<int> D(V + 1, 0);
	
	//에지 리스트 배열
	for (int i = 0; i < E; i++) {
		int A, B;
		long C;

		cin >> A >> B >> C;
		edges.push_back(Edge(C, A, B));
		//가중치, 노드1, 노드2
	}
	sort(edges.begin(), edges.end());

	//유니온 파인드 배열
	for (int i = 1; i <= V; i++) {
		D[i] = i;
	}

	//최소 신장 트리 생성
	int t = 0;
	while (count_edge < V - 1) {//노드의 개수 -1 ==> 엣지 개수
		flag = Union(get<1>(edges[t]), get<2>(edges[t]), D);
		if (flag == 1) {//엣지 추가된 것
			result += get<0>(edges[t]);
			count_edge++;
		}
		//사이클 형성 막기 위해 엣지 추가 안함
		t++;
	}
	cout << result;
}