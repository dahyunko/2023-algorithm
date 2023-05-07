#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<cmath>
#include<tuple>

using namespace std;

/*2251- 물통*/

typedef tuple<int, int, int>info;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int A, B, C;
	cin >> A >> B >> C;

	vector<int>ans;
	bool visited[201][201][201] = {false};

	queue<info>q;
	q.push({ 0,0,C });

	while (!q.empty()) {
		int a = get<0>(q.front());
		int b = get<1>(q.front());
		int c = get<2>(q.front());
		q.pop();

		if (visited[a][b][c]) continue;
		visited[a][b][c] = true;
		if (a==0)ans.push_back(c);

		if (a + b > B) q.push({ a - (B - b),B,c });
		else q.push({ 0,a + b,c });
		if (a + c > C) q.push({ a - (C - c),B,C });
		else q.push({ 0,b,c + a });

		if (b + a > A) q.push({ A,b - (A - a),c });
		else q.push({ a + b, 0, c });
		if (b + c > C) q.push({ a,b - (C - c),C });
		else q.push({ a, 0, c + b });

		if (c + a > A) q.push({ A,b,c - (A - a) });
		else q.push({ a + c, b, 0 });
		if (c + b > B) q.push({ a,B,c - (B - b) });
		else q.push({ a, b + c, 0 });
	}

	int temp;
	sort(ans.begin(), ans.end());
	for (auto e : ans) { 
		cout << e << ' '; 
	}
}