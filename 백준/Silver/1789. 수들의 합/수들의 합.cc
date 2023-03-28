/*수들의 합*/
#include<iostream>
#include<string>
#include<cmath>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>

using namespace std;

typedef long long ll;

int main() {
	ll S, ans = 0;

	cin >> S;

	for (int i = 1;; i++) {
		ans++;
		if (S - i <= i)break;
		S -= i;
	}

	cout << ans;
}