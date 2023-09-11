#include<vector>
#include<queue>
#include<string>
#include<algorithm>

using namespace std;

int p[4] = {1, -1, 0 , 0};
int q[4] = {0 , 0, 1, -1};

struct info{int x, y, cnt;};

int solution(vector<vector<int> > maps)
{
    int answer = -1;
    int n = maps.size();
    int m = maps[0].size();
    
    vector<vector<bool>>visited(n, vector<bool>(m, false));
    queue<info>pq;
    pq.push({n-1, m-1, 1});
    
    while(!pq.empty()){
        info v = pq.front();
        pq.pop();
        
        
        if(v.x == 0 && v.y == 0){
            answer = v.cnt;
            break;
        }
        
        if(visited[v.x][v.y]) continue;
        visited[v.x][v.y] = true;
        
        for(int i=0;i<4;i++){
            int a = v.x+p[i];
            int b = v.y+q[i];
            
            if(a >= 0 && a < n && b >= 0 && b < m && maps[a][b] == 1 && !visited[a][b]) pq.push({a,b,v.cnt+1});
        }   
    }

    return answer;
}