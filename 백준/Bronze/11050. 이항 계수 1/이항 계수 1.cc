/*076(11050)- 이항계수*/
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

void fac(int n, int k) {
	int result = 1, d = 1;

	for (int i = 0; i < k; i++) result *= (n - i);
	for (int i = 1; i <= k; i++) d *= i;

	result /= d;
	cout<< result;
}

int main() {
	int N, K, result;
	cin >> N >> K;

	fac(N, K);
}