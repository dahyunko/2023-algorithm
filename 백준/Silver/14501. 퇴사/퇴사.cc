/*085(14501)- 퇴사 준비하기*/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

typedef pair<int, int> info;

int main() {
    int N;
    cin >> N;

    vector<int>D(N + 2);//결과
    vector<int>T(N + 1);
    vector<int>P(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> T[i] >> P[i];
    }

    for (int i = N; i > 0; i--) {
        if (T[i] + i > N + 1) {
            D[i] = D[i + 1];
        }
        else {
            D[i] = max(D[i + 1], P[i] + D[i + T[i]]);
        }
    }

    cout << D[1];
}