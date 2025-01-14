/*10773*/
#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <limits.h>

using namespace std;

int main() {
	int K;
	long long result = 0;
	cin >> K;

	stack<int> s;

	for (int i = 0; i < K; i++) {
		int now;
		cin >> now;

		if (now == 0) {
			result -= s.top();
			s.pop();
		}
		else {
			result += now;
			s.push(now);
		}
	}

	cout << result;
}