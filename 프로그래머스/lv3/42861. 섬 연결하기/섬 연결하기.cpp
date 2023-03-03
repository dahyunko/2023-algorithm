#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>

using namespace std;
typedef tuple<int, int, int> edge;

int find(int a, vector<int> &parent){
    if(parent[a] == a) return a;
    return parent[a] = find(parent[a], parent);
}

void Union(int a, int b, vector<int> &parent){
    a = find(a, parent);
    b = find(b, parent);
    
    if(a!=b) parent[b] =a ;
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    
    vector<int> parent(n);
    for(int i=0;i<n;i++) parent[i] = i;
    
    priority_queue<edge, vector<edge>, greater<edge>>pq;
    for(int i=0;i<costs.size();i++){
        pq.push(make_tuple(costs[i][2], costs[i][0], costs[i][1]));
    }
    
    int cnt =0, cost=0;
    while(!pq.empty()){
        edge v = pq.top();
        pq.pop();
        
        if(cnt == n-1) break;
        
        int w = get<0>(v);
        int s = get<1>(v);
        int e = get<2>(v);
        
        if(find(s, parent) != find(e, parent)){
            Union(s, e, parent);
            cost += w;
            cnt++;
        }   
    }
    
    answer= cost;
    
    return answer;
}