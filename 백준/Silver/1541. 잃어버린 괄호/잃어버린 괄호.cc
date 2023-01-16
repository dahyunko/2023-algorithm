/*036(1541)*/
//split이용, string sstream 선언
#include<sstream>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;
//split 선언
vector<string> split(string input, char delimiter) {
	vector<string> result;
	stringstream mydata(input);
	string splitdata;

	while (getline(mydata, splitdata, delimiter)) {
		result.push_back(splitdata);
	}
	return result;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string sen;
	cin >> sen;
	vector<string> A = split(sen, '-');
	
	int sum = 0;

	for (int i = 0; i < A.size(); i++) {
		vector<string> B = split(A[i], '+');
		int temp = 0;
		for (int j = 0; j < B.size(); j++) {
			temp += stoi(B[j]);
		}
		if (i == 0) sum = temp;
		else sum -= temp;
	}

	cout << sum;
}