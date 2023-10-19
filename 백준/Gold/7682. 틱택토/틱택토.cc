/*7682*/
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
#include<limits.h>
#include<cmath>

using namespace std;

char A[3][3];

bool check_case(char c) {
	bool isfind = false;

	//가로
	for (int i = 0; i < 3; i++) {
		if (A[i][0] == c && A[i][1] == c && A[i][2] == c) isfind = true;
	}

	//세로
	for (int i = 0; i < 3; i++) {
		if (A[0][i] == c && A[1][i] == c && A[2][i] == c) isfind = true;
	}

	//대각선
	if (A[0][0] == c && A[1][1] == c && A[2][2] == c) isfind = true;
	if (A[0][2] == c && A[1][1] == c && A[2][0] == c) isfind = true;
	
	return isfind;
}

int main() {
	while (true) {
		string now;
		cin >> now;
		if (now == "end") break;

		int cx = 0, co = 0;

		for (int i = 0; i < now.length(); i++) {
			int a = i / 3;
			int b = i % 3;

			if (now[i] == 'O') co++;
			else if (now[i] == 'X') cx++;

			A[a][b] = now[i];
		}

		if (co > cx) cout << "invalid\n";
		else if (co == cx) {
			//0가 이기는 경우
			if (check_case('O')) cout << "valid\n";
			else cout << "invalid\n";
		}
		else if(cx == co + 1){
			//X가 이기는 경우
			if (check_case('X') && !check_case('O')) cout << "valid\n";
			else if (cx == 5 && co == 4) {// 게임 판이 가득 찾을 경우
				if (!check_case('X') && !check_case('O')) cout << "valid\n";
				else cout << "invalid\n";
			}
			else cout << "invalid\n";
		}
		else cout << "invalid\n";
	}
}