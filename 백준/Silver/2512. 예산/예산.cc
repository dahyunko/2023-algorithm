#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include <queue>
#include <cmath>
#include<limits.h>
#include<set>

using namespace std;

int main() {
	int N, M, ans, sum = 0;
	cin >> N;
	vector<int>A(N);

	for (int i = 0; i < N; i++) {
		cin >> A[i];
		sum += A[i];
	}
	cin >> M;

	sort(A.begin(), A.end());

	if (M > sum) {
		cout << A[N - 1];
		return 0;
	}

	int start = 0, end = A[N - 1];//모든 수가 예산보다 클 수 있
	while (start <= end) {
		int mid = (start + end) / 2;
		sum = 0;

		for (int i = 0; i < N; i++) {
			if (mid >= A[i]) sum += A[i];
			else sum += mid;
		}

		if (M >= sum) {//sum이 작을 경우
			ans = mid;
			start = mid + 1;
		}
		else {
			end = mid-1;
		}
	}
	cout << ans;
}