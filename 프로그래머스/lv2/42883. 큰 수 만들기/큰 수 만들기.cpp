#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    
    int ans_size = number.length()-k;
    int s_idx = 0;
    
    for(int i=0;i<ans_size;i++){
        char max_int = number[s_idx];
        int max_idx = s_idx;
        
        for(int j=s_idx;j<=k + i;j++){
            if(max_int < number[j]){
                max_idx = j;
                max_int = number[j];
            }
        }
        s_idx = max_idx+1;
        answer += max_int;
    }
    
    return answer;
}