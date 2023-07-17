/*2075*/
#include <iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<limits.h>
#include<map>
#include<set>
#include<queue>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
	int N;
	cin >> N;

	priority_queue<ll, vector<ll>, greater<ll>>pq;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int now;
			cin >> now;

			if (pq.size() < N) {
				pq.push(now);
				continue;
			}

			ll v = pq.top();
			if (v < now) {
				pq.pop();
				pq.push(now);
			}
		}
	}
	cout << pq.top();
}