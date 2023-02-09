/*13398*/
#include <iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<string>

using namespace std;

int main() {
	int N;
	cin >> N;

	vector<long> A(N+1);
	//dp로 해결해야함
	vector<long> left(N+1, 0);
	vector<long> right(N+1, 0);
	for (int i = 1; i <= N; i++) cin >> A[i];

	left[1] = A[1];
	long result = left[1];
	for (int i = 2; i <= N; i++) {
		left[i] = max(left[i - 1] + A[i], A[i]);
		result = max(result, left[i]);
	}

	right[N] = A[N];
	for (int i = N-1; i > 0; i--) {
		right[i] = max(right[i + 1] + A[i], A[i]);
	}

	for (int i = 2; i <= N -1; i++) {
		result = max(left[i - 1] + right[i + 1], result);
	}

	cout << result;
}