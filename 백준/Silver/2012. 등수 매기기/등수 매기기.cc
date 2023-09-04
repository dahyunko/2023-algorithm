#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include <queue>
#include<stack>
#include <cmath>
#include<limits.h>
#include<set>
#include<map>

using namespace std;
typedef long long ll;

int main() {
	int N;
	ll sum = 0;
	cin >> N;
	vector<int>A(N);

	for (int i = 0; i < N; i++) cin >> A[i];
	
	sort(A.begin(), A.end());
	for (int i = 0; i < N; i++) sum += abs(i + 1 - A[i]);

	cout << sum;
}