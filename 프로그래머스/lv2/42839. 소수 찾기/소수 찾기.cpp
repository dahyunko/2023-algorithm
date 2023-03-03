#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
int ans[7] = {0};

void dfs(vector<int> &A, vector<int> &chart, vector<bool> &visited, int n, int cnt){
    if(n == cnt){
        int temp =0;
        int c =0;
        for(int i=n-1;i>=0;i--){
            temp += ans[i] * pow(10, c++);
        }
        //소수 탐색
        if(temp < 2) return;
        int flag = 0;
        for(int i=2;i<=sqrt(temp);i++){
            if(temp % i == 0) return;
        }
        if(find(chart.begin(), chart.end(), temp) == chart.end()){
            chart.push_back(temp);
        }
        return;
    }
    
    for(int i=0;i<A.size();i++){
        if(!visited[i]){
            visited[i] = true;
            ans[cnt] = A[i];
            dfs(A, chart, visited, n, cnt+1);
            visited[i] = false;
        }
    }
}

int solution(string numbers) {
    int answer = 0;
    
    vector<int> A;
    vector<int> chart;
    for(int i=0;i<numbers.length();i++) A.push_back(numbers[i]-'0');
    
    vector<bool> visited(A.size(), false);
    
    for(int i=1;i<=A.size();i++){
        dfs(A, chart, visited, i, 0);
    }
    
    answer = chart.size();   
    
    return answer;
}