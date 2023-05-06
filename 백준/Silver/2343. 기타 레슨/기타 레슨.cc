/*2343*/
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
using namespace std;

int main() {
	int N, M;
	cin >> N >> M;

	int left = 0, right = 0;
	vector<int> A(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		left = max(left, A[i]);
		right += A[i];
	}

	while (left <= right) {
		int mid = (left + right) / 2;
		int sum = 0, count = 0;

		for (int i = 0; i < N; i++) {
			if (sum + A[i] > mid) {
				count++;
				sum = 0;
			}
			sum += A[i];
		}
		if (sum != 0) count++;
		if (count > M)left = mid + 1;
		else right = mid - 1;
	}
	
	cout << left;
}