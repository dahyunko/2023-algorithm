/*062(11430)- 경로 찾기*/
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	int D[101][101];
	int N;
	
	cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> D[i][j];
		}
	}

	for (int k = 1; k <= N; k++) {
		for (int s = 1; s <= N; s++) {
			for (int e = 1; e <= N; e++) {
				//k 경로가 존재하면 s->e 존재함
				if (D[s][k] == 1 && D[k][e] == 1) {
					D[s][e] = 1;
				}
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cout << D[i][j] <<' ';
		}
		cout << '\n';
	}
}