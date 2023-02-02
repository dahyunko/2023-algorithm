/*041(11689)- 서로소 구하기*/
//오일러 피 함수 구하기: p[i] = p[i] - p[i]/k(소인수??);
#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
#include<vector>

using namespace std;

typedef long long ll;

int main() {
	ll N;

	cin >> N;
	ll result = N;
	
	for (ll i = 2; i <= sqrt(N); i++) {
		if (N % i == 0) {//i가 N의 소인수
			result = result - result / i;

			while (N % i == 0) N /= i;
		}
	}

	if (N > 1) {//소인수가 누락된 경우
		result = result - result / N;
	}

	cout << result;
}