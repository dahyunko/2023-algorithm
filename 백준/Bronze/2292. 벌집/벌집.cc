/*2292*/
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include <queue>
#include <cmath>
#include<limits.h>
#include<set>
#include<map>

using namespace std;

int main() {
	int N;
	cin >> N;

	int cnt = 1;
	int temp = 1;
	int num = 6;

	while (N > temp) {
		temp += num;
		cnt++;
		num += 6;
	}

	cout << cnt;	
}