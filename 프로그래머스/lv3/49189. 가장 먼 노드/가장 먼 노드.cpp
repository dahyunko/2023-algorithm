#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <limits.h>

using namespace std;

typedef pair<int, int>info;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    
    vector<vector<int>> graph(n+1);
    vector<bool>visited(n+1, false);
    vector<int>dep(n+1, 0);
    
    for(int i=0;i<edge.size();i++){
        int s = edge[i][0];
        int e = edge[i][1];
        
        graph[s].push_back(e);
        graph[e].push_back(s);
    }
    
    queue<int> q;
    q.push(1);
    dep[1] = 0;
    visited[1] = true;
    
    while(!q.empty()){
        int v = q.front();
        
        q.pop();
        
        for(int i=0;i<graph[v].size();i++){
            int t = graph[v][i];
            if(!visited[t]){
                visited[t] = true;
                dep[t] = dep[v]+1;
                q.push(t);
            }
        }        
    }  
    
    int m = *max_element(dep.begin(),dep.end());
    for(int i=1;i<n+1;i++){
        if(dep[i] == m) answer++;
    }
    
    return answer;
}