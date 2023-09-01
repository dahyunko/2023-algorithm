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

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;

	priority_queue<int, vector<int>, greater<int>>pq;

	for (int t = 0; t < N; t++) {
		int now;
		cin >> now;

		if (now != 0) {
			pq.push(now);
			continue;
		}
		//cout << "답 :";
		if (pq.empty()) {
			cout << 0 << '\n';
			continue;
		}

		int v = pq.top();
		cout << v << '\n';
		pq.pop();
	}
}