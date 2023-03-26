#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
#include <string>

using namespace std;

/*부분 문자열*/
#include <string.h>

int main() {
	string s, p;
	cin >> s >> p;

	if (strstr((char*)s.c_str(), (char*)p.c_str()) != NULL) cout << 1;
	else cout << 0;
}