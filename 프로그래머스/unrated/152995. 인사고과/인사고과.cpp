#include <string>
#include <vector>
#include <tuple>
#include <queue>
#include <algorithm>

using namespace std;
typedef tuple<int, int, int> info;
typedef pair<int, int> info2;

int solution(vector<vector<int>> scores) {
    int answer = 0;
    
    int n = scores.size();
    vector<info>r_scores;
    vector<int>chart(n, 0);
    
    for(int i=0;i<n;i++){
        r_scores.push_back(make_tuple(scores[i][0], scores[i][1], i));
    }
    sort(r_scores.begin(), r_scores.end());
    
    for(int i=0;i<n-1;i++){
        info now = r_scores[i];
        int now1 = get<0>(now), now2 = get<1>(now), now_idx = get<2>(now);
        int flag =0;
        
        for(int j=i+1;j<n;j++){
            info next = r_scores[j];
            int next1 = get<0>(next), next2 = get<1>(next), next_idx = get<2>(next);
            
            if(now1<next1 && now2<next2) {flag = 1; break;}
        }
        if(flag == 1) chart[now_idx] = -1;        
    }
    
    if(chart[0] == -1) return chart[0];
    
    priority_queue<info2, vector<info2>, less<info2>> pq;
    for(int i=0;i<n;i++){
        if(chart[i] == -1) continue;
        pq.push(info2(scores[i][0] + scores[i][1], i));
    }
    
    int cnt=1, p = 0, temp=-1;
    while(!pq.empty()){
        info2 v = pq.top();
        pq.pop();
        
        if(temp == -1){
            chart[v.second] = cnt;
            temp = v.first;
            p++;
        }
        else if(temp == v.first){
            chart[v.second] = cnt;
            p++;
        }else if(temp > v.first){
            temp = v.first;
            cnt += p;
            chart[v.second] = cnt;
            p = 1;
        }
        if(v.second == 0) break;
    }
        
    answer = chart[0];
    return answer;
}