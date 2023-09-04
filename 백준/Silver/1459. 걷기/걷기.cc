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
	ll X, Y, W, S;
	cin >> X >> Y >> W >> S;

	if (X < Y) swap(X, Y);

	vector<ll> ans(3, 0);
	ans[0] = (X + Y) * W;

	//대각선으로만
	if ((X + Y) % 2 == 0) ans[1] = X * S;
	else ans[1] = (X - 1) * S + W;

	//대각선 + 선분
	ans[2] = Y * S + (X - Y) * W;

	cout << *min_element(ans.begin(), ans.end());
}