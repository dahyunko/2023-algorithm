/*31(1300)*/
#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
#include<vector>

using namespace std;

int main() {
	int N, K;
	cin >> N >> K;
	
	vector<int> A(N + 1);
	for (int i = 1; i <= N; i++) A[i] = i;
	int l = 1, r = K;
    long result =0;
    
	while (l <= r) {
		int mid = (l + r) / 2;
		int cnt = 0;
	
		//각 행의 mid와 같거나 작은 수 개수
		for (int i = 1; i <= N; i++) {
			cnt += min(N, mid / A[i]);
		}

		//cnt와 mid값 비교하면서 l,r값 조정
		if (cnt >= K){
            r = mid - 1;
            result = mid;
        }
		else l = mid + 1;
	}

	//k번째 수
	cout << result;
}