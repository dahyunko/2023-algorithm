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
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N, M;
	cin >> N >> M;
	vector<string>s(N);
	vector<int>A(N);

	for (int i = 0; i < N; i++) cin >> s[i] >> A[i];
	
	//포인터 이용
	for (int t = 0; t < M; t++) {
		int now;
		cin >> now;

		int start = 0, end = N - 1;
		while (start < end ) {
			int mid = (start + end) / 2;

			if (A[mid] < now) {//클 경우
				start = mid+1;
			}
			else {//작거나 같을 경우
				end = mid;
			}
		}

		cout << s[start]<<'\n';
	}
}