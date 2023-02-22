#include <string>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> info;
int mod = 1000000007;

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
        
    vector<vector<int>>cnt(n+1,vector<int>(m+1, 0));
    
    //웅덩이 설정
    for(int i=0;i<puddles.size();i++){
        int a = puddles[i][0];
        int b = puddles[i][1];
        cnt[b][a] = -1;
    }
    
    cnt[0][1] = 1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(cnt[i][j] != -1){
                if(cnt[i][j-1] != -1 && cnt[i-1][j] != -1){
                    cnt[i][j] = (cnt[i][j-1]+ cnt[i-1][j])% mod;
                }else if(cnt[i][j-1] != -1 && cnt[i-1][j] == -1){
                    cnt[i][j] = cnt[i][j-1];
                }else if(cnt[i][j-1] == -1 && cnt[i-1][j] != -1){
                    cnt[i][j] = cnt[i-1][j];
                }else if(cnt[i][j-1] == -1 && cnt[i-1][j] == -1){
                    cnt[i][j] = 0;
                }
            }    
        }
    }
    
    answer = cnt[n][m]%mod;
    
    return answer;
}