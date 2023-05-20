#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<algorithm>
#include<climits>
#include<tuple>
#include<cmath>

using namespace std;

typedef long long ll;
typedef tuple<ll, int, int> edge;
vector<int> parent;

int find(int a) {
	if (a == parent[a]) return a;
	return parent[a] = find(parent[a]);
}

void Union(int a, int b) {
	a = find(a);
	b = find(b);

	if (a != b) parent[b] = a;
}


int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int N;
		double E = 0.0;
		cin >> N;

		vector<ll> X(N);
		vector<ll> Y(N);
		parent.resize(N);

		for (int i = 0; i < N; i++) cin >> X[i];
		for (int i = 0; i < N; i++) cin >> Y[i];
		for (int i = 0; i < N; i++) parent[i] = i;

		cin >> E;

		priority_queue<edge, vector<edge>, greater<edge>>pq;

		for (int i = 0; i < N-1; i++) {
			for (int j = i + 1; j < N; j++) {
				ll temp;
				temp = abs(X[i] - X[j])* abs(X[i] - X[j]) + abs(Y[i] - Y[j])* abs(Y[i] - Y[j]);
				pq.push({ temp, i, j });
			}
		}

		int bridge_cnt = 0;
		ll result = 0;

		while (!pq.empty()) {
			edge v = pq.top();
			ll w = get<0>(v);
			int s = get<1>(v);
			int e = get<2>(v);
			pq.pop();

			if (find(s) != find(e)) {
				Union(s, e);
				bridge_cnt++;
				result += w;
			}
		}
		result = round(result * E);
		cout << '#' << test_case << ' ' << result << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}