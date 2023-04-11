#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int sale[4] = {10, 20, 30, 40};
vector<int> list(7);
int per=0, pay=0;
//dp로해결

void dfs(vector<vector<int>>& users, vector<int>& emoticons, int cnt){
    //사용자 계산
    if(cnt == m){
        int t_per=0, t_pay = 0;
        //사용자
        for(int i=0;i<n;i++){
            int s = users[i][0];
            int mon = users[i][1];
            int temp = 0;
            
            //이모티콘 구매
            for(int j=0;j<m;j++){
                if(list[j] < s) continue;
                temp += emoticons[j]*(100 - list[j])*0.01;
                if(temp >= mon) {//서비스 가입
                    temp = 0;
                    t_per++;
                    break;
                }
            }
            t_pay += temp;
        }
        
        //결과 저장
        if(per < t_per){
            per = t_per;
            pay = t_pay;
        }
        else if(per == t_per) pay = max(pay, t_pay);
        return;
    }
    
    //이모티콘 할인율 백트레킹
    for(int i=0;i<4;i++){
        list[cnt] = sale[i];
        dfs(users, emoticons, cnt+1);
    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> answer;
    
    n = users.size();
    m = emoticons.size();

    dfs(users, emoticons, 0);
    
    answer.push_back(per);
    answer.push_back(pay);
    
    return answer;
}