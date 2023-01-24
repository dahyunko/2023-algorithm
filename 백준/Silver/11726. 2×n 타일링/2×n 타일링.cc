/*077(11726)- 2*n 타일링*/
//동적프로그래밍- 피보나치 수열
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<long>D(N + 1);
    D[0] = 1;
    D[1] = 1;
    for (int i = 2; i <= N; i++) {
        D[i] = D[i - 1] + D[i - 2];
        D[i] %= 10007;
    }

    cout << D[N];
}