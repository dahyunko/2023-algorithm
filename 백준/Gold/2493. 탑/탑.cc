#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include <queue>
#include<stack>
#include <cmath>
#include<limits.h>
#include<set>
#include<map>

using namespace std;

struct info {
	int idx, num;
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;

	vector<int>A(N);
	vector<int>D(N);

	stack<info>s;
	D[0] = 0;
	for (int i = 0; i < N; i++) {
		cin >> A[i];

		if (s.empty()) {
			s.push({i, A[i]});
			continue;
		}
		while (!s.empty() && s.top().num < A[i]) {
			s.pop();
		}
		if (s.empty()) {
			s.push({ i, A[i] });
			D[i] = 0;
			continue;
		}
		D[i] = s.top().idx+1;
		s.push({ i, A[i] });
	}
	
	for (int i = 0; i < N; i++) cout << D[i] << ' ';
}