#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    
    int n = triangle.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    
    dp[0][0] = triangle[0][0];
    for(int i=0;i<n-1;i++){
        for(int j=0;j<=i;j++){
            dp[i+1][j] = max(dp[i+1][j], triangle[i+1][j]+ dp[i][j]); 
            dp[i+1][j+1] = max(dp[i+1][j+1], triangle[i+1][j+1]+ dp[i][j]); 
        }
    }
    
    answer = *max_element(dp[n-1].begin(), dp[n-1].end());
    return answer;
}