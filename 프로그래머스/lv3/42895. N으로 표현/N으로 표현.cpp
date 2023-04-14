#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

int solution(int N, int number) {
    int answer = 0;
    if(N==number) return 1;
    vector<unordered_set<int>>dp(8);
    dp[0].insert(N);
    
    for(int k=1;k<8;k++){
        
        int result = N;
        for(int i=1;i<=k;i++) result = result * 10 + N;
        dp[k].insert(result);
        
        for(int i=0;i<k;i++){
            for(int j=0;j<k;j++){
                if(i+j+1 != k) continue;
                for(int a:dp[i]){
                    for(int b:dp[j]){
                        dp[k].insert(a+b);
                        if(a-b>0) dp[k].insert(a-b);
                        dp[k].insert(a*b);
                        if(a/b>0)dp[k].insert(a/b);
                    }
                }
            }
        }
        if(dp[k].find(number)!= dp[k].end()){
            return k+1;
        }
    }
    
    return -1;
}