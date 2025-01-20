import java.io.*;
import java.util.*;


public class Main {
  static int N;
  static Pair[] eggPairs= new Pair[9];
  static boolean[] isDead = new boolean[9];

  static class Pair{
    int s, w;
  
    public Pair(int s, int w){
      this.s = s; // 내구도
      this.w = w; // 무게
    }
  }

  static int backTrackingEgg(int v){
    if(v >= N) return 0;
    if(isDead[v]) return backTrackingEgg(v+1);
    int cnt = 0;

    for(int i=0; i<N ; i++){
      if(v == i) continue;
      if(isDead[i]) continue;
      
      // 내구도가 상대방의 계란의 무게만큼 깍인다
      int temp = 0;
      int v_s = eggPairs[v].s;
      int i_s = eggPairs[i].s;
      eggPairs[v].s -= eggPairs[i].w;
      eggPairs[i].s -= eggPairs[v].w;
      
      if(eggPairs[v].s <= 0) {
        isDead[v] = true;
        temp++;
      }
      if(eggPairs[i].s <= 0) {
        isDead[i] = true;
        temp++;
      }

      cnt = Math.max(cnt, backTrackingEgg(v+1) + temp);

      if(isDead[v]) isDead[v] = false;
      if(isDead[i]) isDead[i] = false;
      eggPairs[v].s = v_s;
      eggPairs[i].s = i_s;
    }

    return cnt;
  }

  public static void main(String[] args) throws IOException{
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st;

    N = Integer.parseInt(br.readLine());
    
    for(int i=0;i<N;i++){
      st = new StringTokenizer(br.readLine());
      int s = Integer.parseInt(st.nextToken());
      int w = Integer.parseInt(st.nextToken());

      eggPairs[i] = new Pair(s, w);
      isDead[i] = false;
    }

    System.out.println(backTrackingEgg(0));
  }
}