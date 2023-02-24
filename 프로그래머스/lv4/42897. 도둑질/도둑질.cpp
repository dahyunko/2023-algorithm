#include <string>
#include <vector>

using namespace std;

int solution(vector<int> money) {
    int answer = 0;
    
    int n = money.size();
    int dp[1000001][2]={0};
    int rdp[1000001][2]={0};
    
    dp[0][0] = 0;
    dp[0][1] = money[0];
    for(int i=1;i<n-1;i++){
        dp[i][0] = max(dp[i-1][0], dp[i-1][1]); 
        dp[i][1] = dp[i-1][0] + money[i]; 
    }
    answer = max(dp[n-2][0], dp[n-2][1]);
    
    rdp[n-1][0] = 0;
    rdp[n-1][1] = money[n-1];
    for(int i=n-2;i>0;i--){
        rdp[i][0] = max(rdp[i+1][0], rdp[i+1][1]); 
        rdp[i][1] = rdp[i+1][0] + money[i]; 
    }
    answer = max(answer, max(rdp[1][0], rdp[1][1]));
    
    return answer;
}