/*2251*/
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<stack>
#include<cmath>
#include<tuple>
#include<limits.h>

using namespace std;

typedef tuple<int, int, int> info;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int A, B, C;
	cin >> A >> B >> C;

	vector<int>ans;

	bool D[201][201][201] = {false};

	queue<info>q;
	q.push({ 0, 0, C });

	while (!q.empty()) {
		int a, b, c;
		a = get<0>(q.front());
		b = get<1>(q.front());
		c = get<2>(q.front());
		q.pop();

		if (D[a][b][c]) continue;
		D[a][b][c] = true;
		if (a == 0) ans.push_back(c);

		if (a + b <= B) q.push({ 0,a + b,c });
		else q.push({ a - (B - b), B,c });
		if (a + c <= C) q.push({ 0, b ,c + a });
		else q.push({ a - (C - c), b,C });

		if (b + c <= C) q.push({ a,0,c+b });
		else q.push({ a ,b-(C-c) ,C});
		if (b + a <= A) q.push({ b + a, 0 ,c });
		else q.push({ A, b - (A - a),c });

		if (c + a <= A) q.push({ c + a ,b, 0 });
		else q.push({ A ,b ,c -(A-a)});
		if (c + b <= B) q.push({ a, c + b ,0 });
		else q.push({ a , B, c-(B-b)});
	}

	sort(ans.begin(), ans.end());
	for (auto it : ans) cout << it << ' ';
}