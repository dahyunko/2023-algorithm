/*100(2166)- 다각형의 넓이*/
#include<cmath>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<long> x(N+1, 0);
    vector<long> y(N+1, 0);

    for (int i = 0; i < N; i++) {
        cin >> x[i] >> y[i];
    }
    x[N] = x[0];
    y[N] = y[0];

    double result = 0;
    for (int i = 0; i < N; i++) {
        result += (x[i] * y[i + 1]) - (x[i + 1] * y[i]);
    }

    cout<<fixed;
    cout.precision(1);
    cout << abs(result) / 2;
}