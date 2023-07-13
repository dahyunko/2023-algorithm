/*7682*/
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<sstream>
#include<limits.h>
#include<tuple>

using namespace std;

char A[3][3];

bool find_if_there_is_line(char c) {
	int cnt = 0;
	if (A[0][0] == A[0][1] && A[0][1] == A[0][2] && A[0][0] == c) cnt++;
	if (A[1][0] == A[1][1] && A[1][1] == A[1][2] && A[1][0] == c) cnt++;
	if (A[2][0] == A[2][1] && A[2][1] == A[2][2] && A[2][0] == c) cnt++;
	if (A[0][0] == A[1][1] && A[1][1] == A[2][2] && A[0][0] == c) cnt++;
	if (A[2][0] == A[1][1] && A[1][1] == A[0][2] && A[2][0] == c) cnt++;
	if (A[0][0] == A[1][0] && A[1][0] == A[2][0] && A[0][0] == c) cnt++;
	if (A[0][1] == A[1][1] && A[1][1] == A[2][1] && A[0][1] == c) cnt++;
	if (A[0][2] == A[1][2] && A[1][2] == A[2][2] && A[0][2] == c) cnt++;

	if (cnt > 0) return true;
	return false;
}

int main() {
	
	while(true) {
		string now;
		cin >> now;

		if (now == "end") break;
		
		//판 생성
		int t = 0, x_cnt =0, o_cnt= 0;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (now[t] == 'O') o_cnt++;
				else if(now[t] == 'X') x_cnt++;
				A[i][j] = now[t++];
			}
		}
		
		bool o_has = find_if_there_is_line('O');
		bool x_has = find_if_there_is_line('X');

		if (!o_has && !x_has && x_cnt == 5 && o_cnt == 4) cout << "valid\n";
		else if (x_has && !o_has && x_cnt == o_cnt + 1) cout << "valid\n";
		else if (!x_has && o_has && x_cnt == o_cnt) cout << "valid\n";
		else cout << "invalid\n";
	}
}