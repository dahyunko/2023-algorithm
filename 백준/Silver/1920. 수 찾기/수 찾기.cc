#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//STL를 이용한 이진탐색을 이용하여 탐색
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	int now;
	
	cin >> N;
	int A[100000]={};

	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	sort(A, A+N);

	cin >> M;//찾는 횟수
	for (int i = 0; i < M; i++) {
		cin >> now;
		cout<< binary_search(A, A + N, now) <<'\n';
	}
}
