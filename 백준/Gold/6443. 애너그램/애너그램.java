import java.io.*;
import java.util.*;

public class Main {
  static int T, N;
  static StringBuilder sb = new StringBuilder();
  static int[] alpha;
  static int[] list = new int[21];

  static void makeWords(int c){
    if(c == N){
      String s = "";
      for(int i=0;i<N;i++){
        char x = (char) (list[i]+'a');
        s += x;
      }
      sb.append(s);
      sb.append('\n');
      return;
    }

    for(int i=0;i<26;i++){
      if(alpha[i] <= 0) continue;

      list[c] = i;
      alpha[i]--;
      makeWords(c + 1);
      alpha[i]++;
    }
  }

  public static void main(String[] args) throws Exception{
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    
    T = Integer.parseInt(br.readLine());

    for(int t=0;t<T;t++){
      String sen = br.readLine();
      N = sen.length();

      alpha = new int[27];
      for(int i=0;i<N;i++) {
        char c = sen.charAt(i);
        alpha[c - 'a']++;
      }
      
      makeWords(0);
    }

    System.out.println(sb);
  }
}