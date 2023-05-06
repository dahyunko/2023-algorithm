/*019-k번째 수 구하기
//퀵 정렬 이용pivot이용
퀵: 분할, 정복, 
*/
#include <iostream>
#include <vector>
#include <algorithm>//swap이용

using namespace std;

int main() {
    	//시간 초과
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, k;

	cin >> N >> k;
	vector<int> A(N, 0);

	for (int i = 0; i < N; i++) {
		cin >>A[i];
	}
	
    sort(A.begin(),A.end());
    
	cout << A[k-1] << '\n';
}