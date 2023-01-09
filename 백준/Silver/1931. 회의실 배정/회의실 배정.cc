#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio;
	cin.tie(NULL);
	cout.tie(NULL);

	int N, count = 0;

	cin >> N;
	vector<pair<int,int>> A(N);

	for (int i = 0; i < N; i++) {
		cin >> A[i].second >> A[i].first;//종료 값을 first에 입력
	}

	//종료 시간 순으로 정렬
	sort(A.begin(), A.end());

	
	int end = -1;
	for (int i = 0; i < N; i++) {
		if (A[i].second >= end) {
			end = A[i].first;//종료 시간
			count++;
		}
	}

	cout << count<<'\n';
}