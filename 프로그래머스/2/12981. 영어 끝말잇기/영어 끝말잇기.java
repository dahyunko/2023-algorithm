import java.util.*;

class Solution {
    public int[] solution(int n, String[] words) {
        int[] answer = {};
        
        int N = words.length;
        Set<String> set = new HashSet<>();
        boolean isWrong = false;
        int a, b;
        a = b = 0;
        
        char prevChar = words[0].charAt(words[0].length() - 1);
        set.add(words[0]);
        for(int t=1;t<N;t++){
            String word = words[t];
            
            if(word.length() == 1 ) isWrong = true;
            
            // 같은 단어 있는지 확인
            if(set.contains(word)) isWrong = true;
            
            // 끝말잇기 되는지
            if(prevChar != word.charAt(0)) isWrong = true;
            
            if(isWrong) {
                System.out.println(word);
                a = t%n + 1;
                b = t/n + 1;
                break;
            }
            
            set.add(word);
            prevChar = word.charAt(word.length() - 1);
        }

        return new int[]{a, b};
    }
}