/*멀티탭 스케줄링*/
#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
#include <string>

using namespace std;

typedef pair<int, int> info;

int main() {
	int N, K;

	cin >> N >> K;

	vector<int> T(N);//멀티탭 구멍
	vector<int> S(K);//사용 순서
	int cnt = 0;

	for (int i = 0; i < K; i++) {
		cin >> S[i];
	}

	int t = 0;
	for (int i = 0; i < K; i++) {
		//존재함
		if (find(T.begin(), T.end(), S[i]) != T.end()) continue;
		else {
			if (t < N) {
				T[t++] = S[i];
			}
			else {
				//가장 오랫동안 사용 안하는거 탐색
				int idx = -1, last = -1;
				for (int j = 0; j < N; j++) {
					int temp = 0;
					for (int t = i + 1; t < K; t++) {
						if (S[t] == T[j]) break;
						temp++;
					}
					if (temp > last) {
						last = temp;
						idx = j;
					}
				}

				T[idx] = S[i];
				cnt++;
			}
		}
	}

	cout << cnt;
}