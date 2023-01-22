/*084(1463)- 1로 만들기*/
//동적 계획법- 피보나치 수열_Bottom-up
//피보나치 수열: D[n] = D[n-1] + D[n-2]
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main() {
    int n;

    cin >> n;
    vector<int> D(n + 1, 0);

    D[1] = 0;// 초기화

    //동적 계획법- 피보나치 수열_Bottom-up
    for (int i = 2; i <= n; i++) {
        D[i] = D[i - 1] + 1;
        if (i % 2 == 0) D[i] = min(D[i], D[i / 2] + 1);
        if (i % 3 == 0) D[i] = min(D[i], D[i / 3] + 1);
    }
    cout << D[n];
}