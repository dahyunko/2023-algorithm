/*2193- 이친수 구하기*/
#include <iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<string>

using namespace std;

int main() {
	int N;

	cin >> N;
	vector<long long>A(N + 1, 0);

	A[1] = 1;
	A[2] = 1;
	for (int i = 3; i <= N; i++) {
		A[i] = A[i - 1] + A[i - 2];
	}
	cout << A[N];
}