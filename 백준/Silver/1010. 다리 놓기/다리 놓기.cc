/*079(1010)- 다리 놓기*/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

void fac(int n, int k) {
    long result = 1;
    int Mod = 10007;
    vector<int> A;
    vector<int> B;

    for (int i = 0; i < k; i++) {
        A.push_back(n - i);
    }
    for (int i = 1; i <= k; i++) {
        B.push_back(i);
    }

    for (int i = 0; i < B.size(); i++) {
        for (int j = 0; j < A.size(); j++) {
            if (B[i] != 1) {
                int n;
                n = gcd(B[i], A[j]);
                B[i] /= n;
                A[j] /= n;
            }
        }
    }

    for (int j = 0; j < A.size(); j++) {
        result = result * A[j];
    }

    cout << result<<'\n';
}

int main() {
    int T;//질의 수
    cin >> T;

    for (int i = 0; i < T; i++) {
        int n, m;
        cin >> n >> m;
        
        fac(m, n);
    }
}