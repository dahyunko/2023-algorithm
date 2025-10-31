import java.io.*;
import java.util.*;

class Solution {
    static class INFO{
        int flag; // enter : 1, leave: 2
        String id;
        
        INFO(int flag, String id) {
            this.flag = flag;
            this.id = id;
        }
    }
    public String[] solution(String[] record) {
        
        int N = record.length;
        List<INFO> logs = new ArrayList<>();
        Map<String, String> map = new HashMap<>();
        
        for(int i=0;i<N;i++) {
            String[] temp = record[i].split(" ");
            if("Enter".equals(temp[0])) {
                logs.add(new INFO(1, temp[1]));
            }
            else if("Leave".equals(temp[0])) {
                logs.add(new INFO(2, temp[1]));
                continue;
            }
            
            map.put(temp[1], temp[2]); 
        }
        
        
        String[] answer = new String[logs.size()];
        
        for(int i=0;i<logs.size();i++) {
            answer[i] = map.get(logs.get(i).id) + "님이 ";
            switch(logs.get(i).flag) {
                case 1 :
                    answer[i] += "들어왔습니다.";
                    break;
                case 2 :
                    answer[i] += "나갔습니다.";
                    break;
            }
        }
        return answer;
    }
}