#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    
    int n = prices.size();
    answer.resize(n);
    answer[n-1] = 0;
    
    for(int i=0;i<n-1;i++){
        
        int temp =0;
        for(int j = i;j<n-1;j++){
            if(prices[i]<=prices[j]) temp++;
            else break;
        }
        answer[i] = temp;
    }
    
    return answer;
}