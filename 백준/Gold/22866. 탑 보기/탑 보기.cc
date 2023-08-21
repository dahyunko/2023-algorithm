/*22866*/
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

struct info {
	int h, i;//높이, 번호
};

int main() {
	int N;
	cin >> N;

	vector<int> build(N);
	vector<int> A(N, 0);//보이는 건물의 개수
	vector<vector<int>> B(N);//보이는 건물의 개수
	stack<info>s;

	for (int i = 0; i < N; i++) cin >> build[i];

	// -> 탐색
	for (int i = 0; i < N; i++) {
		if (s.empty()) {
			s.push({ build[i], i });
			continue;
		}

		//현재 자신보다 작은 건물 버리기
		while (s.top().h <= build[i]) {
			s.pop();
			if (s.empty()) break;
		}
		if (!s.empty()) B[i].push_back(s.top().i);
		A[i] += s.size();

		//현재 건물 추가
		s.push({ build[i], i });
	}
	while (!s.empty()) s.pop();

	// <- 탐색
	for (int i = N-1; i >= 0; i--) {
		if (s.empty()) {
			s.push({ build[i], i });
			continue;
		}

		//현재 자신보다 작은 건물 버리기
		while (s.top().h <= build[i]) {
			s.pop();
			if (s.empty()) break;
		}
		if (!s.empty()) B[i].push_back(s.top().i);
		A[i] += s.size();

		//현재 건물 추가
		s.push({ build[i], i });
	}

	for (int i = 0; i < N; i++) {
		cout << A[i] << ' ';
		
		if (B[i].size() == 1) cout << B[i][0] + 1;
		else if(B[i].size() == 2) {
			int a = abs(i - B[i][0]);
			int b = abs(i - B[i][1]);
			
			if (a == b) {
				cout << min(B[i][0], B[i][1]) + 1;
			}
			else if (a < b) cout << B[i][0] + 1;
			else cout << B[i][1] + 1;
		}
		
		cout << '\n';
	}
}