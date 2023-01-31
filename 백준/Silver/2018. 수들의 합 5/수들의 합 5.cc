#include <iostream>
#include <vector>

using namespace std;

int main() {
	//시간 초과
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	int start=1, end=1;
	int count = 1;//자기 자신 포함 시작
	int sum = 1;
	//시작이 end로 시작하기 때문에 1 더하고 진행해야함, start때 1빼고 시작

	//입력
	cin >> N;

	while (end != N) {
		if (sum > N) {
			sum = sum - start; //왼쪽 값을 삭제 시키는 것
			start++;
		}
		else if (sum < N) {
			end++; 
			sum = sum + end;// end로 범위를 확장
		}
		else if (sum == N) {
			end++; 
			sum = sum + end; 
			count++;
		}
	}

	cout << count << '\n';
}