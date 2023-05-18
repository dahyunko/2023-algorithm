#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	for(test_case = 1; test_case <= T; ++test_case)
	{
		string sen;
		cin >> sen;

		int len = sen.length();
		int result = 100000000;

		for (int j = 1; j < len; j++) {
			int a = stoi(sen.substr(0, j));
			int b = stoi(sen.substr(j, len));

			result = min(result, a + b);
		}

		cout << '#' << test_case<< ' ' << result << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}