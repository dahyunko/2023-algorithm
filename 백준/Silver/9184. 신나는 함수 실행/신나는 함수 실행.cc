/*9184*/
#include <iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

//메모리제이션 필요, 값을 저장함으로서 같은 연산 반복 안함
int store[21][21][21];

int solve(int a, int b, int c) {
	if (a <= 0 || b <= 0 || c <= 0) return 1;
	if (a > 20 || b > 20 || c > 20) return solve(20, 20, 20);
	if (store[a][b][c])return store[a][b][c];
	if (a < b && b < c) {
		store[a][b][c] = solve(a, b, c - 1) + solve(a, b - 1, c - 1) - solve(a, b - 1, c);
		return store[a][b][c];
	}
	else {
		store[a][b][c] = solve(a - 1, b, c) + solve(a - 1, b - 1, c) + solve(a - 1, b, c - 1) - solve(a - 1, b - 1, c - 1);
		return store[a][b][c];
	}
}

int main() {
	int a, b, c;

	cin >> a >> b >> c;
	while (true) {
		if (a == -1 && b == -1 && c == -1) break;
		cout << "w("<<a<<", " << b << ", " << c << ")" << " = " << solve(a, b, c) << '\n';
		cin >> a >> b >> c;
	}
}