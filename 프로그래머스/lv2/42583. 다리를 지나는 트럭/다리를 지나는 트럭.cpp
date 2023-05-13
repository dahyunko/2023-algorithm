#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;
typedef pair<int,int>info;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    
    queue<info>q;
    int i=1, t=1, on_weight=truck_weights[0];
    q.push({truck_weights[0], bridge_length+0});
    while(true){
        while(!q.empty() && t >= q.front().second) {
            on_weight -= q.front().first;
            q.pop();
        }
        
        if(on_weight + truck_weights[i] <= weight ){
            on_weight += truck_weights[i];
            q.push({truck_weights[i], bridge_length+t});
            cout<<bridge_length+t<<'\n';
            i++;
        }
        if(i == truck_weights.size()) break;
        
        t++;
    }
    while(!q.empty()) {
        t = q.front().second;
        q.pop();
    }
    
    answer = t+1;
    return answer;
}