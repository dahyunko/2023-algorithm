/*2812*/
#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <limits.h>

using namespace std;
int N, K;

int main() {
	cin >> N >> K;

	string str;
	cin >> str;

	vector<int>num(N);
	vector<bool>visited(N, false);

	// 숫자 저장
	for (int i = 0; i < N; i++) num[i] = str[i] - '0';
	
	// stack 사용해야함
	stack<int>s;

	// O(N) 시간에 해결해야함
	for (int i = 0; i < N; i++) {
		if (s.empty()) {
			s.push(num[i]);
			continue;
		}

		bool flag = false;
		while (!s.empty() && K > 0 && s.top() < num[i]) {
			s.pop();
			flag = true;
			K--;
		}

		s.push(num[i]);
	}

	vector<int> answer;
	while (!s.empty()) {
		// K 개 다 지워졌는지 확인해야함
		if (K > 0) K--;
		else answer.push_back(s.top());
		s.pop();
	}
	for (int i = answer.size() - 1; i >= 0; i--) cout << answer[i];
}