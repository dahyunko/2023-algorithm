#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

int main() {
	int M, N;
	int k = 1;

	cin >> M >> N;
	vector<int>pn(N + 1,0);//0이면 소수, 1이면 소수 아님

	pn[1] = 1;
	for (int i = 2; i <= sqrt(N); i++) {
		if (pn[i] == 0) {
			for (int j = i + 1; j <= N; j++) {
				if (j % i == 0) {//소수아님
					pn[j] = 1;
				}
			}
		}
	}

	for (int i = M; i <= N; i++) {
		if (pn[i] == 0) {
			cout << i << '\n';
		}
	}
}