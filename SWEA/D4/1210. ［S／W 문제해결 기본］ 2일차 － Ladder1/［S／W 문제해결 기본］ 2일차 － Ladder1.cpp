#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<algorithm>
#include<climits>

using namespace std;
int A[101][101];
int result;
bool isFind;

void dfs(int m1, int m2, vector<vector<bool>>&visited) {
	if (isFind) return;
	if (m1 == 0) {
		result = m2;
		isFind = true;
		return;
	}

	visited[m1][m2] = true;
	if (m2 - 1 >= 0 && A[m1][m2 - 1] == 1 && !visited[m1][m2 - 1]) {
		dfs(m1, m2 - 1, visited); 
	}
	else if (m2 + 1 < 100 && A[m1][m2 + 1] == 1 && !visited[m1][m2 + 1]) {
		dfs(m1, m2 + 1, visited); 
	}
	else if (m1 - 1 >= 0 && A[m1 - 1][m2] == 1 && !visited[m1 - 1][m2]) {
		dfs(m1 - 1, m2, visited); 
	}
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	T = 10;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int case_num;
		cin >> case_num;
		int e1, e2;
		isFind = false;
		vector<vector<bool>>visited(101, vector<bool>(101, false));

		//그래프 생성
		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 100; j++) { 
				cin >> A[i][j]; 
				if (A[i][j] == 2) {
					e1 = i;
					e2 = j;
				}
			}
		}
		dfs(e1, e2, visited);
		cout << '#' << case_num << ' ' << result << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}