/*014(11286)- 절대값 힙 구하기*/
#include <queue>
#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
#include<vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;

	cin >> N;
	priority_queue<int, vector<int>, greater<int>> pq_pos;
	priority_queue<int, vector<int>, less<int>> pq_neg;
	for (int i = 0; i < N; i++) {
		int now;
		cin >> now;

		if (now > 0) {
			pq_pos.push(now);
		}
		else if (now < 0) {
			pq_neg.push(now);
		}	
		else if (now == 0) {
			if (pq_pos.empty() && pq_neg.empty()) cout << 0 << '\n';
			else {
				if (pq_pos.empty()) {
					cout << pq_neg.top() << '\n';
					pq_neg.pop();
				}
				else if (pq_neg.empty()) {
					cout << pq_pos.top() << '\n';
					pq_pos.pop();
				}
				else {
					if (pq_pos.top() >= abs(pq_neg.top())) {
						cout << pq_neg.top() << '\n';
						pq_neg.pop();
					}
					else {
						cout << pq_pos.top() << '\n';
						pq_pos.pop();
					}
				}
			}
		}
	}
}