/*018-ATM인출 시간 계산하기*/
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	int N;
	int sum =0;

	cin >> N;

	vector<int> arr(N,0);
	vector<int> result;

	//시간 입력
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	//올림차순 정렬
	sort(arr.begin(), arr.end());

	//시간 입력
	for (int i = 0; i < N; i++) {
		sum += arr[i] * ( N - i);
	}

	cout << sum << '\n';
}