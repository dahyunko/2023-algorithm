/*032(11047)- 동전개수의 최소값 구하기*/
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	int N, K;
	int count = 0;

	cin >> N >> K;

	vector<int> A(N, 0);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	//동전의 개수
	for (int i = N - 1; i >= 0; i--) {
		if (K >= A[i]) {
			int t;
			t = K / A[i];
			count += t;
			K = K % A[i];

		}
	}

	cout << count;
}