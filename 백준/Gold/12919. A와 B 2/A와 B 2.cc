/*12919*/
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>

using namespace std;

int flag = 0;

void S_same_T(string &S, string &T){
	if (flag == 1) return;
	if (S.size() == T.size()) {
		if (S == T) {
			flag = 1;
			return;
		}
		else return;
	}
	if (S.size() > T.size()) return;

	//a삭제
	string temp = T;
	int n = T.size()-1;
	if (temp[n] == 'A') {
		temp.erase(temp.begin() + n);
		S_same_T(S, temp);
	}

	//b삭제
	string temp2 = T;
	n = T.size() - 1;
	reverse(temp2.begin(), temp2.end());//역순 정렬
	if (temp2[n] == 'B') {
		temp2.erase(temp2.begin() + n);
		S_same_T(S, temp2);
	}
}

int main() {
	string S, T;
	cin >> S >> T;

	S_same_T(S, T);
	if (flag == 1) cout << 1;
	else cout << 0;
}