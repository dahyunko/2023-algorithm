/*1932- 정수 삼각형*/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

/*1932- 정수 삼각형*/

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    vector<vector<int>> graph(N+1, vector<int> (N+1));
    graph.resize(N + 1);

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= i; j++) {
            cin >> graph[i][j];
        }
    }

    for (int i = 2; i <= N; i++) {
        for (int j = 1; j <= i; j++) {
            if (j == 1) {
                graph[i][j] += graph[i - 1][j];
            }
            else if (j == i) {
                graph[i][j] += graph[i - 1][j-1];
            }
            else {
                if (graph[i - 1][j - 1] > graph[i - 1][j]) {
                    graph[i][j] += graph[i - 1][j - 1];
                }
                else {
                    graph[i][j] += graph[i - 1][j];
                }
            }
        }
    }

    cout << *max_element(graph[N].begin(), graph[N].end());
}