#include <string>//split 라이브러리
#include <sstream>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<string> split(string input, char delimiter) {
	vector<string>result;
	stringstream mystream(input);
	string splitdata;

	while (getline(mystream, splitdata, delimiter)) {
		result.push_back(splitdata);
	}

	return result;
}

int addAll(string A) {
	int sum = 0;
	//+를 기준으로 데이터 나누기
	vector<string> A_vector = split(A, '+');

	//string -> int로 변환 후 다 더함
	for (int i = 0; i < A_vector.size(); i++) {
		sum += stoi(A_vector[i]);
	}

	return sum;
}

int main() {
	string sen;
	int result=0;

	cin >> sen;
	//-기준으로 데이터 나누기
	vector<string> sen_vector = split(sen, '-');

	for (int i = 0; i < sen_vector.size(); i++) {
		int temp = addAll(sen_vector[i]);
		if (i == 0) {
			result += temp;
		}
		else {//나누기를 기준으로 다 빼기
			result -= temp;
		}
	}

	cout << result;
}