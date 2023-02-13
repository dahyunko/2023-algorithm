/*9461- 파도반 수열*/
#include <iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

int main() {
	int T, N;

	cin >> T;
	vector<long long> A(101, 0);
	A[1] = 1;
	A[2] = 1;
	A[3] = 1;
	A[4] = 2;
	A[5] = 2;

	for (int i = 6; i <= 100; i++) {
		A[i] = A[i - 1] + A[i - 5];
	}

	for (int i = 0; i < T; i++) {
		cin >> N;
		cout << A[N]<<'\n';
	}
}