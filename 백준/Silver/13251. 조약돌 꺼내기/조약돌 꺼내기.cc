/*080(13251)- 조약돌 꺼내기*/
#include<numeric>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;


int main() {
    int N, K, sum =0;
    cin >> N;

    vector<int>A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        sum += A[i];
    }
    cin >> K;

    vector<double>pro(N);
    double result = 0;
    for (int i = 0; i < N; i++) {
        if (A[i] >= K) {
            pro[i] = 1.0;
            for (int k = 0; k < K; k++) {
                pro[i] *= (double)(A[i] - k) / (sum - k);
            }
            result += pro[i];
        }
    }
    
    cout.precision(9);
    cout << result;
}