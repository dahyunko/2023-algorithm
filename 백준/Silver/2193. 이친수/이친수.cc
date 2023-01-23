/*086(2193)- 이친수 구하기*/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
typedef pair<long, long> info;//1 개수, 0 개수

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N;

    vector<info> A;
    A.resize(N + 1);

    A[0].first = 1;
    A[0].second = 0;

    for (int i = 1; i < N; i++) {
        A[i].first = A[i - 1].second;
        A[i].second = A[i - 1].first + A[i - 1].second;
    }

    cout << A[N - 1].first + A[N - 1].second;
}