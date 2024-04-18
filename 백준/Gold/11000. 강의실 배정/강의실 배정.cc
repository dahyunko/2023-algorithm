#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <limits.h>
#include <cmath>

using namespace std;

struct info {
	int s, e;
};

bool cmp(info& a, info& b) {
	return a.s < b.s;
}

int main() {
	int N;

	cin >> N;
	vector<info>c(N);

	for (int i = 0; i < N; i++) {
		cin >> c[i].s >> c[i].e;
	}

	sort(c.begin(), c.end(), cmp);

	priority_queue<int, vector<int>, greater<int>>pq;
	pq.push(c[0].e);

	for (int i = 1; i < N; i++) {
		int v = pq.top();

		if (v <= c[i].s) {
			pq.pop();
		}
		pq.push(c[i].e);
	}
	
	cout << pq.size();
}