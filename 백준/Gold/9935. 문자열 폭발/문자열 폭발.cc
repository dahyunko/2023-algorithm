/*9935*/
#include<stack>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main() {
	string sen;
	string bom;

	cin >> sen;
	cin >> bom;

	stack<char> s;

	for (int i = 0; i < sen.length(); i++) {
		s.push(sen[i]);
		int idx = bom.length() - 1;
		char c = s.top();
		if (c == bom[idx]) {
			int flag= -1;
			for (int j = idx; j >= 0; j--) {
                if (s.empty()) {//stack이 비었을 때 고려
					flag = j;
					break;
				}
				c = s.top();
				if (c != bom[j]) {
					flag = j;
					break;
				}
				s.pop();
			}
			if (flag != -1) {
				for (int j = flag+1; j <= idx; j++) s.push(bom[j]);
			}
		}
	}
	
	string ans;
	if (s.empty()) cout << "FRULA";
	else { 
		while (!s.empty()) {
			ans.push_back(s.top());
			s.pop();
		}
		for (int i = ans.size() - 1; i >= 0; i--) cout << ans[i];
	}
}