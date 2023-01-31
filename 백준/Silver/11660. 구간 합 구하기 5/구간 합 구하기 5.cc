#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*004*/
#include <vector>;

int main() {
	//시간 초과
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	int x1, y1, x2, y2;
	int result;

	cin >> N >> M;

	//벡터사용
	vector<vector<int>> A(N + 1, vector<int>(N + 1, 0));
	vector<vector<int>> D(N + 1, vector<int>(N + 1, 0));

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> A[i][j];
			//구간 합 구하기
			D[i][j] = D[i][j - 1] + D[i - 1][j] - D[i - 1][j - 1] + A[i][j];
		}
	}

	for (int i = 0; i < M; i++) {
		cin >> x1>> y1>>x2>>y2;
		cout << D[x2][y2]-D[x1-1][y2]-D[x2][y1-1]+D[x1-1][y1-1] << '\n';
	}
}