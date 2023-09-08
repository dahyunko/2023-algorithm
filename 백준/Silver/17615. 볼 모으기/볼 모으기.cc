#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
#include<limits.h>
#include<cmath>

using namespace std;

int N, result = INT_MAX;
vector<char>A;

void move_ball(char x) {
	int cnt = 0;
	bool check = false;
	//처음 색이 같은 색일 경우를 대비해서 check로 확인 진행

	//왼쪽
	for (int i = 0; i < N; i++) {
		if (A[i] != x) check = true;
		else if (check && A[i] == x) cnt++;
	}
	result = min(result, cnt);

	cnt = 0;
	check = false;
	//오른쪽
	for (int i = N - 1; i >= 0; i--) {
		if (A[i] != x) check = true;
		else if (check && A[i] == x) cnt++;
	}
	result = min(result, cnt);
}


int main() {
	cin >> N;

	A.resize(N);
	for (int i = 0; i < N; i++) cin >> A[i];

	//R, B 둘다 왼, 오 옮겼을 때의 개수 중 가장 작은 값을 출력
	move_ball('R');
	move_ball('B');

	cout << result;
}