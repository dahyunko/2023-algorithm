/*
기수 정렬: 값을 놓고 비교할 자릿수를 정한 다음 해당 자릿수만 비교
bucket 이용: n값 정해서 나머지로 계산하는 거..!!
시간 복잡도: O(kn)

일의자리 수로 정렬 -> 십의자리 기준으로 데이터 저정
*/
#include <iostream>
#include <vector>

using namespace std;

int main() {
	//시간 초과
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, count[10001]={0};
    int now;
    
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> now;
		count[now]++;
	}

	for (int i = 0; i < size(count); i++) {
		while (count[i] > 0) {
			cout << i << '\n';
			count[i]--;
		}
	}
}