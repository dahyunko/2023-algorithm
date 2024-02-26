/*2696*/
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <sstream>
#include <limits.h>
using namespace std;

int T, N;

int main() {
	cin >> T;

	for (int t = 0; t < T; t++) {
		cin >> N;

		int now, mid ;
		vector<int> ans;
		priority_queue < int, vector<int>, greater<int>>pq1; // 큰거
		priority_queue < int, vector<int>, less<int>>pq2; // 작은거

		cin >> now;
		mid = now;
		ans.push_back(mid);
		for (int i = 1; i < N; i++) {
			cin >> now;

			if (now > mid) {
				pq1.push(now);
			}
			else {
				pq2.push(now);
			}

			if (i % 2 == 0) {
				// 중앙값 찾기

				if (pq1.size() == pq2.size()) {
					ans.push_back(mid);
				}
				else if (pq1.size() > pq2.size()) {
					pq2.push(mid);
					mid = pq1.top();
					pq1.pop();
					ans.push_back(mid);
				}
				else if (pq1.size() < pq2.size()) {
					pq1.push(mid);
					mid = pq2.top();
					pq2.pop();
					ans.push_back(mid);
				}
			}
		}

		cout << ans.size();
		for (int i = 0; i < ans.size(); i++) {
			if (i % 10 == 0) cout << '\n';
			cout << ans[i] << ' ';
		}
		cout << "\n";
	}
}