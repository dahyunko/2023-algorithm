/*012(1728)-오큰수 구하기*/
#include <deque>
#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
#include<vector>

using namespace std;

typedef pair<int, int> info;

int main() {
	int N;
	
	cin >> N;
	deque<info> dq;
	vector<int> result(N);
	vector<int> A(N);

	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	dq.push_back(info(A[0], 0));

	for (int i = 1; i < N; i++) {
		while (A[i] > dq.back().first) {
			result[dq.back().second] = A[i];
			dq.pop_back();
			if (dq.empty()) break;
		}
		dq.push_back(info(A[i], i));
	}

	while (!dq.empty()) {
		result[dq.back().second] = -1;
		dq.pop_back();
	}

	for (int i = 0; i < N; i++) {
		cout << result[i] << ' ';
	}
}