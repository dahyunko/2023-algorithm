#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer(2);
    
    for(int i=1;i<=yellow;i++){
        int temp = yellow;
        int left, right;
        
        if(temp % i == 0){
            left = i;
            right = temp/i;
            
            if(brown == (left+2+right)*2){
                answer[1] =left+2;
                answer[0] = right+2;
                break;
            }
        }
        
    }
    
    
    return answer;
}