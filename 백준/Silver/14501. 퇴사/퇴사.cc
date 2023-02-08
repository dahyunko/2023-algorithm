/*14501- 퇴사*/
#include <iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<string>

using namespace std;

typedef pair<int, int> info;

int main() {
	int N;

	cin >> N;
	vector<int> T(N + 2);
	vector<int> P(N + 2);
	vector<int> D(N + 2, 0);
	for (int i = 1; i <= N; i++) {
		cin >> T[i] >> P[i];
	}

	for (int i = N; i >0; i--) {
        //중간에 있는 수들 중 N값을 넘어가는 것 존재
		if (i + T[i] > N + 1) {
            D[i] = D[i + 1];
        }else D[i] = max(D[i + T[i]] + P[i], D[i + 1]);
	}
	cout << D[1];
}