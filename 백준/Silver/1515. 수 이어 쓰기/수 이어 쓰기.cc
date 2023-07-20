/*1515*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cmath>
using namespace std;

int main() {
	string s;
	cin >> s;

	int idx = 0;
	for (int i = 1; i <= 99999; i++) {
		string now = to_string(i);

		for (int j = 0; j < now.length(); j++) {
			if (now[j] == s[idx]) {
				idx++;
				if (idx == s.length()) {
					cout << i;
					break;
				}
			}
		}
	}
}