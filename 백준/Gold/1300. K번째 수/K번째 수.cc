/*031(1300)- k번째 수 구하기 */
//idea: k를 넘지 않을 것: start = 1, end = k
//각 행에서 해당 숫자보다 작거나 같은 숫자: n/A[i]개
//이진 탐색
#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
#include<vector>

using namespace std;

int main() {
	int N,K;
	
	cin >> N >> K;
	vector<int> A(N + 1);
	//각 행의 첫번째 숫자 저장
	for (int i = 1; i <= N; i++) A[i] = i;

	//1~K까지 탐색 시작
	int start = 1, end = K;
	long result = 0;
	while (start <= end) {
		int mid = (start + end) / 2;//중앙값
		int cnt = 0;
		//mid보다 작거나 같은 수의 개수
		for (int i = 1; i <= N; i++) {
			//배열을 넘어가는 경우
			cnt += min(mid / A[i], N);
		}

		if (cnt >= K) {
			end = mid - 1;
			//현재 단계의 중앙값을 정답 변수에 저장
			result = mid;
		}
		else start = mid + 1;
	}

	cout << result;
}
