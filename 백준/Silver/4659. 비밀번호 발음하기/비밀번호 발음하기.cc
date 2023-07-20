/*4659*/
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
	while (true) {
		string s;
		cin >> s;
		if (s == "end") break;

		bool is_possible = true, is_contain = false;
		int moumn = 0, zaumn = 0;
		
		
		for (int i = 0; i < s.length(); i++) {
			if (i > 0) {
				if (s[i] == s[i - 1]) {
					if (s[i] != 'e' && s[i] != 'o') {
						is_possible = false;
						break;
					}
				}
			}
			if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
				is_contain = true;
				moumn++;
				zaumn = 0;
			}
			else {
				moumn = 0;
				zaumn++;
			}

			if (moumn > 2 || zaumn > 2) {
				is_possible = false;
				break;
			}
		}
		if (is_possible && !is_contain) is_possible = false;

		if (is_possible) cout << '<' << s << "> is acceptable.\n";
		else cout << '<' << s << "> is not acceptable.\n";
	}
}