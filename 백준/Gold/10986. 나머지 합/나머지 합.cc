#include <iostream>
#include <string>

using namespace std;
#include <vector>;

int main() {
	//시간 초과
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	int num, remainder;
	long result=0;

	cin >> N >> M;

	//벡터사용
	vector<long> A(N+1, 0);//벡터 생성 크기 n+1, 0으로 초기화
	vector<long> D(M, 0);//나머지 값이 같은 수들의 집합

	for (int i = 1; i <= N; i++) {
		cin >> num;
		A[i] = A[i - 1] + num;
	}

	//나머지 값이 같은 수들의 개수 저장
	for (int i = 1; i <= N; i++) {
		remainder = A[i] % M;//A배열에 나머지 값 저장
		
		//0~i까지 구간의 합이 0일 경우
		if (remainder == 0) result++;
		D[remainder]++;//나머지 값이 같은 수의 개수 저장
	}

	for (int i = 0; i < M; i++) {
		if (D[i] > 1) {
			//나머지가 같은 수들 중 2개 뽑기
			result = result + (D[i] * (D[i]-1) / 2);
		}
	}

	cout << result <<'\n';
}