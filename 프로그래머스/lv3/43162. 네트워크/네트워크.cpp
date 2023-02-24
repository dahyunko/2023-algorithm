#include <string>
#include <vector>
#include <queue>

using namespace std;

void bfs(vector<vector<int>>&graph, vector<bool>&visited, int v){
    queue<int> q;
    visited[v] = true;
    q.push(v);
    
    while(!q.empty()){
        v = q.front();
        q.pop();
        
        for(int i=0;i<graph[v].size();i++){
            int t = graph[v][i];
            
            if(!visited[t]){
                visited[t] = true;
                q.push(t);
            }
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    vector<vector<int>>graph(n+1);
    vector<bool>visited(n+1, false);
    
    for(int i=0;i<computers.size();i++){
        for(int j=0;j<computers[i].size();j++){
            if(computers[i][j] == 1) {
                graph[i].push_back(j);
            }
        }
    }
    
    for(int i=0;i<n;i++){
        if(!visited[i]){
            bfs(graph, visited, i);
            answer++;
        }
    }
    
    return answer;
}