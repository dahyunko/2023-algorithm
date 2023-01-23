/*DP 이용*/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    int D[1001][1001];

    for (int i = 0; i <= N; i++) {
        D[i][0] = 1;
        D[i][i] = 1;
        D[i][1] = i;
    }

    for (int i = 2; i <= N; i++) {
        for (int j = 1; j < i; j++) {
            D[i][j] = D[i - 1][j] + D[i - 1][j - 1];
            D[i][j] = D[i][j] % 10007;
        }
    }

    cout << D[N][K];
}