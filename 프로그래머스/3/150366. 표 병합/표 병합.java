import java.io.*;
import java.util.*;

class Solution {
    static Info[][] infoList = new Info[51][51];
    
    static class Info{
        int r, c;
        String word;
        boolean isMerge;
        Info(int r, int c, String word, boolean isMerge){
            this.r = r;
            this.c = c;
            this.word = word;
            this.isMerge = isMerge;
        }
    }
    
    static void changeValue(int r, int c, String value){
        for(int i=1;i<=50;i++){
            for(int j=1;j<=50;j++){
                if(infoList[i][j].r != r || infoList[i][j].c != c) continue;
                infoList[i][j].word = value;
            }   
        }
    }
    
    static void changeValue2(String value1, String value2){
        for(int i=1;i<=50;i++){
            for(int j=1;j<=50;j++){
                if(!infoList[i][j].word.equals(value1)) continue;
                infoList[i][j].word = value2;
            }   
        }
    }
    
    static void changeValue3(int r1, int c1, int r2, int c2, String value){
        for(int i=1;i<=50;i++){
            for(int j=1;j<=50;j++){
                if(infoList[i][j].r != r1 || infoList[i][j].c != c1) continue;
                
                // update
                updateData(i, j, r2, c2, value, true);
            }   
        }
    }
    
    static void unMerge(int r, int c){
        for(int i=1;i<=50;i++){
            for(int j=1;j<=50;j++){
                if(infoList[i][j].r != r || infoList[i][j].c != c) continue;
                
                // update
                updateData(i, j, i, j, "", false);
            }   
        }
    }
    
    static void updateData(int i, int j, int r, int c, String word, boolean isMerge){
        infoList[i][j].r = r;
        infoList[i][j].c = c;
        infoList[i][j].word = word;
        infoList[i][j].isMerge = isMerge;
    }
    
    public String[] solution(String[] commands) {
        String[] answer = {};
        List<String> result = new ArrayList<>();
        StringTokenizer st;
        
        // init
        for(int i=1;i<=50;i++){
            for(int j=1;j<=50;j++){
                infoList[i][j] = new Info(i, j, "", false);
            }   
        }
        
        // commands 실행
        for(int i=0;i<commands.length;i++){
            st = new StringTokenizer(commands[i]);
            List<String> demands = new ArrayList<>();
            
            // demand 확인
            while(st.hasMoreTokens()){ demands.add(st.nextToken()); }
            
            if(demands.get(0).equals("UPDATE") && demands.size() == 4){
                int r = Integer.parseInt(demands.get(1));
                int c = Integer.parseInt(demands.get(2));
                String value = demands.get(3);
                
                if(!infoList[r][c].isMerge){
                    infoList[r][c].word = value;
                    continue;
                }
                
                // merge 요소 확인
                changeValue(infoList[r][c].r, infoList[r][c].c , value);
            }
            else if(demands.get(0).equals("UPDATE") && demands.size() == 3){
                String value1 = demands.get(1);
                String value2 = demands.get(2);
                
                changeValue2(value1, value2);
            }
            else if(demands.get(0).equals("MERGE")){
                int r1 = Integer.parseInt(demands.get(1));
                int c1 = Integer.parseInt(demands.get(2));
                int r2 = Integer.parseInt(demands.get(3));
                int c2 = Integer.parseInt(demands.get(4));
                
                if(infoList[r1][c1].r == infoList[r2][c2].r && infoList[r1][c1].c == infoList[r2][c2].c) continue;
                
                // 둘다 머지 안된 상태 일 경우

                // 값이 있는 지 확인
                if(infoList[r1][c1].word.equals("") && !infoList[r2][c2].word.equals("")){
                  // r2, c2 가 있을 경우
                  changeValue3(infoList[r1][c1].r, infoList[r1][c1].c, infoList[r2][c2].r, infoList[r2][c2].c, infoList[r2][c2].word);   
                  changeValue3(infoList[r2][c2].r, infoList[r2][c2].c, infoList[r2][c2].r, infoList[r2][c2].c, infoList[r2][c2].word);   
                }
                else {
                  // r1, c1 에 값이 있음
                  changeValue3(infoList[r1][c1].r, infoList[r1][c1].c, infoList[r1][c1].r, infoList[r1][c1].c, infoList[r1][c1].word);   
                  changeValue3(infoList[r2][c2].r, infoList[r2][c2].c, infoList[r1][c1].r, infoList[r1][c1].c, infoList[r1][c1].word);   
                }                
            }
            else if(demands.get(0).equals("UNMERGE")){
                int r1 = Integer.parseInt(demands.get(1));
                int c1 = Integer.parseInt(demands.get(2));
                
                if(!infoList[r1][c1].isMerge) continue;
                
                String value = infoList[r1][c1].word;
                unMerge(infoList[r1][c1].r, infoList[r1][c1].c);
                infoList[r1][c1].word = value;
            }
            else if(demands.get(0).equals("PRINT")){
                int r1 = Integer.parseInt(demands.get(1));
                int c1 = Integer.parseInt(demands.get(2));
                
                result.add(infoList[r1][c1].word.equals("") ? "EMPTY": infoList[r1][c1].word);
            }
        }
        
        return result.toArray(String[]::new);
    }
}