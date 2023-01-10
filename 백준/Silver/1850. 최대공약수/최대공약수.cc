/*043(1850)최대공약수 구하기*/
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int mod(long long min, long long max) {
	long long c;

	c = max % min;
	if (c == 0) {
		return min;
	}
	else {
		return mod(c, min);
	}
}

int main() {
	long long A, B, result;

	cin >> A >> B;
	if (A > B) {
		result = mod(B, A);
	}
	else {
		result = mod(A, B);
	}
	for (long i = 0; i < result; i++) {
		cout << 1;
	}
}