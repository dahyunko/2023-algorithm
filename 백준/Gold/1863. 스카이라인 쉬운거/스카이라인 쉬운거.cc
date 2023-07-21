/*1863*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, cnt = 0;
	cin >> N;

	stack<int>s;
	for (int i = 0; i < N; i++) {
		int x, y;
		cin >> x >> y;

		while (!s.empty() && s.top() > y) {
			cnt++;
			s.pop();
		}

		if (!s.empty() && s.top() == y) continue;
		s.push(y);
	}
	while (!s.empty()) {
		if (s.top() > 0)cnt++;
		s.pop();
	}

	cout << cnt;
}