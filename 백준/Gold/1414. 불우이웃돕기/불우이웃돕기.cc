/*066(1414)- 불우이웃돕기*/
//최소신장트리 이용
#include <tuple>;
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

typedef tuple<int, int, int> Edge;

int Find(int a, vector<int> &D) {
	if (a == D[a]) return a;
	else return D[a] = Find(D[a], D);
}

int Union(int a, int b, vector<int>& D) {
	a = Find(D[a], D);
	b = Find(D[b], D);

	if (a != b) {
		D[b] = a;
		return 1;
	}
	else return 2;
}

int main() {
	int N;
	int result = 0, count_edge = 0;
	int flag = 0;

	cin >> N;
	vector<Edge> edges;
	vector<int> D(N + 1,0);

	//엣지 리스트 생성
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			char c;
			int num;
			cin >> c;
			if (c >= 'a' && c <= 'z') num = c - 'a' + 1;
			else if (c >= 'A' && c <= 'Z') num = c - 'A' + 27;
			else if (c == '0') num = c - '0';
			edges.push_back(Edge(num, i, j));
			result += num;
		}
	}
	sort(edges.begin(), edges.end());//가중치 정렬

	//유니온 파인드 배열 생성
	for (int i = 1; i <= N; i++) {
		D[i] = i;
	}

	//총 값 - 최소신장트리
	int t = 0;
	while (count_edge < N - 1) {
		if (get<0>(edges[t]) != 0) {//가중치 0은 존재하지 않는 것
			flag = Union(get<1>(edges[t]), get<2>(edges[t]), D);
			if (flag == 1) {
				count_edge++;
				result -= get<0>(edges[t]);
			}
		}
		t++;
		if (t >= edges.size()) break;//모든 엣지르 돌아도 신장트리가 아닌 경우
	}
	if (count_edge == N - 1) {
		cout << result;
	}else cout << -1;
}