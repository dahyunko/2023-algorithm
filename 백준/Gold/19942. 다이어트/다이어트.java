import java.io.*;
import java.util.*;

public class Main {
  static int N, result = Integer.MAX_VALUE;
  static int mp, mf,ms,mv;
  static List<Info> food = new ArrayList<>();
  static int[] list = new int[16];
  static List<Integer> answer = new ArrayList<>();

  static class Info{
    int mp, mf, ms, mv, price;

    Info(){
    }

    Info(int mp, int mf, int ms, int mv, int price){
      this.mp = mp;
      this.mf = mf;
      this.ms = ms;
      this.mv = mv;
      this.price = price;
    }
  }

  static void makeFood(int v, int c, int cnt, int sumP, int sumF, int sumS, int sumV, int sum){
    if(c == cnt){
      if(sumP < mp || sumV < mv || sumF < mf || sumS < ms) return;
      if(result < sum) return;
      else if(result > sum){
        result = sum;
        answer.clear();
        for(int i=0;i<cnt;i++) answer.add(list[i] + 1);
      }
      else if(result == sum){
        // 문자열 비교
        String sen1="", sen2 = "";
        for(int i: answer) sen1 += Integer.toString(i);
        for(int i=0;i<cnt;i++) sen2 += Integer.toString(list[i] + 1);

        if(sen1.compareTo(sen2) > 0) {
          answer.clear();
          for(int i=0;i<cnt;i++) answer.add(list[i] + 1);
        }
      }
      return;
    }

    for(int i=v; i<N;i++){
      list[c] = i;
      makeFood(i+1, c+1, cnt, sumP + food.get(i).mp, sumF + food.get(i).mf, sumS + food.get(i).ms, sumV + food.get(i).mv, sum + food.get(i).price);
    }
  }

  public static void main(String[] args) throws Exception{
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    
    N = Integer.parseInt(br.readLine());
    StringTokenizer st = new StringTokenizer(br.readLine());
    mp = Integer.parseInt(st.nextToken());
    mf = Integer.parseInt(st.nextToken());
    ms = Integer.parseInt(st.nextToken());
    mv = Integer.parseInt(st.nextToken());

    for(int i=0;i<N;i++){
      st = new StringTokenizer(br.readLine());
      int p = Integer.parseInt(st.nextToken());
      int f = Integer.parseInt(st.nextToken());
      int s = Integer.parseInt(st.nextToken());
      int v = Integer.parseInt(st.nextToken());
      int price = Integer.parseInt(st.nextToken());
      food.add(new Info(p, f, s, v, price));
    }

    for(int i=1;i<=N;i++){
      makeFood(0, 0, i, 0, 0, 0, 0, 0);
    }

    if(result == Integer.MAX_VALUE) {
      System.out.println(-1);
      return;
    }
    System.out.println(result);
    for(int i:answer) System.out.print(i+" ");
  }
}