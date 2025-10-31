import java.util.*;
import java.io.*;

class Solution {
    
    static int[] stringToDate(String str) {
        String[] temp = str.split("\\.");
        int[] date = new int[3]; // 0:year, 1:month, 2:day
        
        date[0] = Integer.parseInt(temp[0]);
        date[1] = Integer.parseInt(temp[1]);
        date[2] = Integer.parseInt(temp[2]);
        
        return date;
    }
    
    static String calDateMonth(int[] date, int month) {
        int[] temp = new int[3];
        temp[2] = date[2];
        int year = month/12;
        month = month%12;
        
        if(date[1] <= month ) {
            temp[1] = date[1] + 12 - month;
            temp[0] = date[0] - 1 - year;
        }
        else {
            temp[1] = date[1] - month;
            temp[0] = date[0] - year;
        }
        
        
        String str = Integer.toString(temp[0]) + ".";
        str += (temp[1] < 10 ? "0" : "" ) + Integer.toString(temp[1]) + ".";
        str += (temp[2] < 10 ? "0" : "" ) + Integer.toString(temp[2]);
        
        return str;
    }
    
    public int[] solution(String today, String[] terms, String[] privacies) {
        int N = terms.length;
        int M = privacies.length;
        int[] todayArr = stringToDate(today);
        List<Integer> result = new ArrayList<>();
        
        // 현재 일로 부터 해당 개월 수 이전인 값을 map으로 저장
        Map<String, String> map = new HashMap<>();
        for(int i=0;i<N;i++) {
            String[] term = terms[i].split(" ");
            int month = Integer.parseInt(term[1]);

            String calDate = calDateMonth(todayArr, month);
            
            map.put(term[0], calDate);
        }
        
        for(int i=0;i<M;i++) {
            String[] priv = privacies[i].split(" ");
            if(priv[0].compareTo(map.get(priv[1])) <= 0) {
                result.add(i);
            }
        }
        
        int[] answer = new int[result.size()];
        for(int i=0;i<result.size(); i++){
            answer[i] = result.get(i) + 1;
        }
        
        return answer;
    }
}