/*1309*/
#include <iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

static int mod = 9901;
int main() {
	int N;
	cin >> N;

	vector<long> A(N+1, 0);

	A[0] = 1;
	A[1] = 3;

	for (int i = 2; i <= N; i++) {
		A[i] = (A[i - 1] * 2 + A[i - 2]) % mod;
	}

	cout << A[N];
}