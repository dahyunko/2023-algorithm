/*2304*/
#include <utility>
#include <iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<limits.h>
#include<map>
#include<set>
#include<queue>
#include<stack>

using namespace std;

int main() {
	int N;
	cin >> N;
	int ans = 0;
	vector<pair<int, int>>A(N);

	for (int i = 0; i < N; i++) cin >> A[i].first >>A[i].second ;
	sort(A.begin(), A.end());

	int temp = -1, idx;
	for (int i = 0; i < N; i++) {
		if (temp < A[i].second) {
			temp = A[i].second;
			idx = i;
		}
	}

	stack<pair<int, int>>s;
	for (int t = 0; t <= idx; t++) {

		int x=0,y=0;
		while (!s.empty() && s.top().second < A[t].second) {
			x = s.top().first;
			y = s.top().second;
			s.pop();
		}
		if(x>0 && y>0) ans += y * (A[t].first - x);

		if (!s.empty() && s.top().second > A[t].second) continue;
		s.push(A[t]);
	}
	if (!s.empty()) {
		ans += s.top().second;
		s.pop();
	}

	for (int t = N-1; t >= idx; t--) {
		int x = 0, y = 0;
		while (!s.empty() && s.top().second <= A[t].second) {
			x = s.top().first;
			y = s.top().second;
			s.pop();
		}
		if (x > 0 && y > 0) ans += y * (x - A[t].first);

		if (!s.empty() && s.top().second > A[t].second) continue;
		s.push(A[t]);
	}

	cout << ans;
}