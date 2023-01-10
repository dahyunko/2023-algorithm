/*042(1934)-최소 공배수 구하기*/
//최소 공배수 = a*b/최대 공약수
//최대 공약수 -> 뉴클리드 호제법 이용 
//둘 중 작은 값으로 계속 나눔 0이 될때까지
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int mod(int min, int max) {
	int c;

	c = max % min;
	if (c == 0) {
		return min;
	}
	else {
		return mod(c, min);
	}
}

int main() {
	int T;
	int A, B, result;

	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> A>>B;
		if (A > B) {
			result = mod(B, A);
		}
		else {
			result = mod(A, B);
		}
		result = A * B / result;
		cout << result << '\n';
	}
}