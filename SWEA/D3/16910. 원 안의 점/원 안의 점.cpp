#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int N;
		cin >> N;

		int cnt = 0;
		int circle = N * N;

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (i * i + j * j <= circle) cnt++;
				else break;
			}
		}

		cnt = cnt * 4 + N * 4 + 1;
		cout << '#' << test_case << ' ' << cnt << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}