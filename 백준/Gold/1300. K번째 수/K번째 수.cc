/*1300*/
#include <iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

int main() {
	int N, K;
	
	cin >> N >> K;
	vector<int>A(N + 1);

	for (int i = 1; i <= N; i++) A[i] = i;

	int left = 1, right = K;
	while (left <= right) {
		int cnt = 0;
		int mid = (left + right) / 2;

		for (int i = 1; i <= N; i++) {
			cnt += min(N, mid / A[i]);
		}

		if (cnt >= K) right = mid - 1;
		else left = mid + 1;
	}

	cout << left;
}