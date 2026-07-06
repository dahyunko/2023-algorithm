import java.io.*;
import java.util.*;

class Solution {
    public int[] solution(int[] lottos, int[] win_nums) {
        int[] answer = new int[2];
        
        int sameCnt = 0, zeroCnt = 0;
        
        // 로또 돌리고 같은 숫자 있는지 확인
        for(int i=0;i<6;i++){
            if(lottos[i] == 0) {
                zeroCnt++;
                continue;
            }
            for(int j=0;j<6;j++){
                if(lottos[i] == win_nums[j]){
                    sameCnt++;
                    break;
                }
            }
        }
        
        if(7 - (sameCnt + zeroCnt) > 5) answer[0] = 6;
        else answer[0] = 7 - (sameCnt + zeroCnt);
        
        if(7 - sameCnt > 5) answer[1] = 6;
        else answer[1] = 7 - sameCnt;
        
        return answer;
    }
}