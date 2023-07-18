/*1863*/
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

/*1863*/

int main() {
	int N;
	cin >> N;

	stack<int>s;
	int cnt = 0;

	for (int t = 0; t < N; t++) {
		int x;
		int now;
		cin >> x >> now;

		while (!s.empty() && s.top() > now) {
			s.pop();
			cnt++;
		}
		if (!s.empty() && s.top() == now) continue;
		s.push(now);
	}
	while (!s.empty()) {
		if(s.top() > 0) cnt++;
		s.pop();
	}

	cout << cnt;
}