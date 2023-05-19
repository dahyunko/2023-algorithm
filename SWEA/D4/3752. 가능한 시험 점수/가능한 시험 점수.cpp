#include <map>
#include<numeric>
#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<algorithm>
#include<climits>

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
		vector<int>score(N);
		vector<int>result;
		vector<bool>visited(10001, false);

		for (int i = 0; i < N; i++) cin >> score[i];
		visited[0] = true;
		result.push_back(0);

		for (int i = 0; i < N; i++) {
			int size = result.size();
			for (int j = 0; j < size; j++) {
				int c = result[j] + score[i];
				if (!visited[c]) {
					result.push_back(c);
					visited[c] = true;
				}
			}
		}

		cout <<'#'<< test_case <<' ' << result.size() << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}