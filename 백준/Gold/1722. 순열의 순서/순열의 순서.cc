#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

void kth_elements(long k, int N, vector<long> &F) {
    vector<char>visited(N + 1, 'F');//미사용 벡터 A
    vector<long>result;

    for (int i = 1; i <= N; i++) {
        long cnt = 1;
        for (int j = 1; j <= N; j++) {
            if (visited[j] == 'T') continue;
            
            if (k <= cnt * F[N - i]) {
                k -= ((cnt - 1) * F[N - i]);
                result.push_back(j);
                visited[j] = 'T';
                break;
            }
            cnt++;
        }
    }

    for (int i = 0; i < N; i++) {
        cout << result[i] << ' ';
    }
}

void find_kth(vector<long>& A, vector<long>& F, int N) {
    long result = 1;
    vector<char>visited(N + 1, 'F');//미사용 벡터 A

    for (int i = 1; i <= N; i++) {
        long cnt = 0;
        for (int j = 1; j < A[i]; j++) {
            if (visited[j] == 'F') {
                cnt++;
            }
        }
        result += cnt * F[N - i];
        visited[A[i]] = 'T';
    }

    cout << result;
}

int main() {
    int N, a;

    cin >> N;
    cin >> a;

    vector<long>F(N + 1, 1);
    for (int i = 1; i <= N; i++) {
        F[i] = F[i - 1] * i;
    }

    if (a == 1) {
        long k;
        cin >> k;
        kth_elements(k, N, F);
    }
    else {
        vector<long>A(N + 1, 0);
        for (int i = 1; i <= N; i++) {
            cin >> A[i];
        }
        find_kth(A, F, N);
    }
}