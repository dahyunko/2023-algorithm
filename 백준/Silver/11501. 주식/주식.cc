/*11501*/
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
	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		int N;
		cin >> N;

		vector<int>A(N);
		vector<long long>list(N, 0);
		
		//주가 입력 받음
		for (int i = 0; i < N; i++) cin >> A[i];

		int num = A[N - 1];
		for (int i = N - 2; i >= 0; i--) {
			if (A[i] > num) {
				num = A[i];
				list[i] = list[i + 1];
				continue;
			}
			list[i] = list[i + 1] + num - A[i];			
		}
			
		cout << list[0] << '\n';
	}
}