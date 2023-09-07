#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include <queue>
#include<stack>
#include <cmath>
#include<limits.h>
#include<set>
#include<map>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
	int N;
	cin >> N;

	vector<int>A(N);
	for (int i = 0; i < N; i++) cin >> A[i];

	sort(A.begin(), A.end());
	int ans = INT_MAX;
    int idx = 0;
	int temp = 0;

	for (int i = 0; i < N; i++) {
		if (A[i] + 1 == N - 1 || A[i] == N - 1) {
			ans = min(ans, A[i]);
		}
		else if (A[i] + 1 > N - 1) {//고리가 넘치는 경우
			ans = min(ans, N - 1);
		}
		else if (A[i] + 1 < N - 1) { //고리가 부족한 경우
			while (idx < i) {
				//충분한 경우
				temp += A[idx];
				if (A[i] + temp + 1 == N - (idx + 2) || A[i] + temp == N - (idx + 2)) {
					ans = min(ans, A[i] + temp);
					break;
				}
				else if (A[i] + temp + 1 > N - (idx + 2)){
					ans = min(N - (idx + 2), ans);
					break;
				}
				else {
					idx++;
				}
			}
		}
	}
	
	cout << ans;
}