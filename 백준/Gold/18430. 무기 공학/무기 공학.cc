#include <stdio.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <climits>
#include <queue>
#include <map>
#include <set>

using namespace std;

int N, M;

vector<vector<int>> dy = { {0, 1}, {-1, 0}, {-1, 0}, {0, 1} };
vector<vector<int>> dx = { {-1, 0}, {0, -1}, {0, 1}, {1, 0} };

int DFS(vector<vector<int>>& Boomerang, vector<vector<bool>>& visited, int y, int x)
{
    int result = 0;

    for (int i = 0; i < 4; i++)
    {
        int y1 = y + dy[i][0];
        int x1 = x + dx[i][0];

        int y2 = y + dy[i][1];
        int x2 = x + dx[i][1];

        if (y1 < 0 || y1 >= N || x1 < 0 || x1 >= M) continue;
        if (y2 < 0 || y2 >= N || x2 < 0 || x2 >= M) continue;

        if (visited[y1][x1] || visited[y2][x2]) continue;

        int currentStrenth = Boomerang[y][x] * 2 + Boomerang[y1][x1] + Boomerang[y2][x2];
        visited[y][x] = true;
        visited[y1][x1] = true;
        visited[y2][x2] = true;

        int temp = 0;
        int c = x + 1;
        for (int r = y; r < N; r++)
        {
            for (; c < M; c++)
            {
                if (visited[r][c]) continue;
                temp = max(temp, DFS(Boomerang, visited, r, c));
            }
            c = 0;
        }

        visited[y][x] = false;
        visited[y1][x1] = false;
        visited[y2][x2] = false;

        result = max(result, currentStrenth + temp);
    }

    return result;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;

    vector<vector<int>> Boomerang(N, vector<int>(M, 0));
    vector<vector<bool>> visited(N, vector<bool>(M, false));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> Boomerang[i][j];
        }
    }

    int answer = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            answer = max(answer, DFS(Boomerang, visited, i, j));
        }
    }

    cout << answer;

	return 0;
}