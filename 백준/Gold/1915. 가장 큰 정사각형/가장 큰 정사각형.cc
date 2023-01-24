/*091(1915)- 가장 큰 정사각형 찾기*/
#include<cmath>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main() {
    int n, m;

    cin >> n >> m;

    vector<vector<int>> D;
    D.resize(n);
    //입력
    for (int i = 0; i < n; i++) {
        string now;//string으로 받아야됨
        cin >> now;
        for (int j = 0; j < m; j++) {
            D[i].push_back(now[j] - '0');
        }
    }

    //정사각형 찾기
    int Max = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (D[i][j] == 1 && i > 0 && j > 0) {
                D[i][j] = min(D[i - 1][j - 1], min(D[i - 1][j], D[i][j - 1])) + 1;
            }
            if (Max < D[i][j]) Max = D[i][j];
        }
    }

    cout << Max * Max;
}