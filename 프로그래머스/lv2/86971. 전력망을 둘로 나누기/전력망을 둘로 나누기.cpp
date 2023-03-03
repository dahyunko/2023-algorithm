#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <limits.h>

using namespace std;

int solution(int n, vector<vector<int>> wires) {
    int answer = -1;
    
    vector<vector<int>>graph(n+1);
    vector<bool>visited(n+1, false);
    
    for(int i=0;i<wires.size();i++){
        int a = wires[i][0];
        int b = wires[i][1];
        
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    int result = INT_MAX;
    for(int i=0;i<wires.size();i++){
        int a = wires[i][0];
        int b = wires[i][1];
        int cnt = 0;
        queue<int> q;
        
        visited[a] = true;
        visited[b] = true;
        
        q.push(a);
        while(!q.empty()){
            int v = q.front();
            cnt++;
            q.pop();
            
            for(int i=0;i<graph[v].size();i++){
                int t = graph[v][i];
                
                if(!visited[t]){
                    visited[t] = true;
                    q.push(t);
                } 
            }
        }
        
        result = min(result, abs(cnt - (n - cnt)));   
        fill(visited.begin(), visited.end(), false);
    }
    
    answer = result;
    
    return answer;
}