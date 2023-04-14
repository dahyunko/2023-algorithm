#include <string>
#include <vector>

using namespace std;
int cnt=0;

void dfs(vector<int> &numbers, int target, int c, int sum){
    if(c == numbers.size()){
        if(sum == target)cnt++;
        return;
    }
    
    dfs(numbers, target, c+1, sum + numbers[c]);
    dfs(numbers, target, c+1, sum - numbers[c]);
}



int solution(vector<int> numbers, int target) {
    int answer = 0;
    
    dfs(numbers, target, 0, 0);
    
    answer = cnt;
    return answer;
}