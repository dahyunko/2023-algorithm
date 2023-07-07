/*16918*/
#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<algorithm>
#include<climits>
#include<tuple>
#include<cmath>

using namespace std;

int field[201][201];
int n, m, k;

//boom
void boom(int t) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (field[i][j] == t - 3) { 
				field[i][j] = -1; 
				if (i - 1 >= 0 && field[i-1][j] != t-3) field[i - 1][j] = -1;
				if (i + 1 < n && field[i + 1][j] != t - 3) field[i + 1][j] = -1;
				if (j - 1 >= 0 && field[i][j - 1] != t - 3) field[i][j-1] = -1;
				if (j + 1 < m && field[i][j + 1] != t - 3) field[i][j+1] = -1;
			}
		}
	}
}

//install
void install(int t) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (field[i][j] == -1) field[i][j] = t;
		}
	}
}

int main() {
	int t = 2;

	cin >> n;
	cin >> m;
	cin >> k;

	

	//입력 받음
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) { 
			char c;
			cin >> c;
			if (c == '.') field[i][j] = -1;
			else if (c == '0') field[i][j] = 0;
		}
	}

	//실행
	while (t <= k) {
		if (t % 2 == 0){
			//설치
			install(t);
		}
		else {
			//boom
			boom(t);
		}
		t++;
	}

	//출력
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (field[i][j] == -1) cout << '.';
			else cout << 'O';
		}
		cout<<'\n';
	}
}