/*1541*/
#include<sstream>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
using namespace std;

vector<string>split(string input, char delimiter) {
	vector<string>result;
	stringstream mystream(input);
	string splitdata;

	while (getline(mystream, splitdata, delimiter)) {
		result.push_back(splitdata);
	}
	return result;
}

int main() {
	string sen;
	cin >> sen;

	vector<string>A = split(sen, '-');

	int sum = 0;
	for (int i = 0; i < A.size(); i++) {
		int temp = 0;
		vector<string>B = split(A[i], '+');
		for (int j = 0; j < B.size(); j++) {
			temp += stoi(B[j]);
		}
		if (i == 0) sum = temp;
		else sum -= temp;
	}
	cout << sum;
}