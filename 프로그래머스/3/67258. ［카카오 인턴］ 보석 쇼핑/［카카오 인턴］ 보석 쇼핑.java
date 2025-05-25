import java.util.*;

class Solution {
    public int[] solution(String[] gems) {
        int[] answer = new int[2];
        
        // 보석 종류 개수 세기
        Set<String> gSet = new HashSet<>();
        int gemCnt = 0;
        for(int i = 0;i<gems.length;i++){
            gSet.add(gems[i]);
        }
        gemCnt = gSet.size();
        
        // 가장 짧은 구간 탐색
        Map<String, Integer> gMap = new HashMap<>();
        int s = 0, e = 0, cnt = 0;
        int left = 0, right = 0,  minLength = Integer.MAX_VALUE;
        
        while(true){
            // 아직 모든 보석이 채워지지 않음
            if(cnt < gemCnt){
                if(e == gems.length){ break; }
                gMap.put(gems[e], gMap.getOrDefault(gems[e], 0) + 1);
                
                // 보석이 채워졌으면 cnt + 1
                if(gMap.get(gems[e]) == 1) cnt++;
                e++;                
            }
            // 보석 종류는 모두 존재, 짧은 구간 탐색
            else { 
                // 짧은 구간 확인
                if(minLength > e - s){
                    left = s;
                    right = e;
                    minLength = e - s;
                }
                
                // 보석 빼기
                gMap.put(gems[s], gMap.get(gems[s]) - 1);
                if(gMap.get(gems[s]) == 0) cnt--;
                s++;
            }
        }
        
        answer[0] = left + 1;
        answer[1] = right;
        
        return answer;
    }
}