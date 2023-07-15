#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int dp[501][501]={0};

int solution(vector<vector<int>> t) {
    int answer = 0;
    int n = t.size();
    int m = t[n-1].size();
    
    dp[0][0] = t[0][0];
    for(int i=1;i<n;i++){
        for(int j=0;j<=i;j++){
            if(j==0) dp[i][j] = dp[i-1][j]+t[i][j];
            else if(j == i) dp[i][j] = dp[i-1][j-1]+t[i][j];
            else dp[i][j] = t[i][j] + max(dp[i-1][j], dp[i-1][j-1]);
        }
    }
    
    sort(dp[n-1], dp[n-1]+m);
    answer = dp[n-1][m-1];
    
    return answer;
}