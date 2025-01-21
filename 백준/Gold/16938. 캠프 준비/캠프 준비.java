import java.io.*;
import java.util.*;

public class Main {
  static int N,L,R,X, result = 0;
  static int[] array;
  static int[] list = new int[16];

  static void chooseNumber(int v, int c, int sum, int cnt){
    if(sum > R) return;
    if(c == cnt){
      if(sum < L) return;
      if((list[c-1] - list[0]) < X ) return;
      result++;
      return;
    }

    for(int i=v;i<N;i++){
      list[c] = array[i];
      chooseNumber(i+1, c+1, sum + array[i], cnt);
    }
  }

  public static void main(String[] args) throws Exception{
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());

    N = Integer.parseInt(st.nextToken());
    L = Integer.parseInt(st.nextToken());
    R = Integer.parseInt(st.nextToken());
    X = Integer.parseInt(st.nextToken());

    st = new StringTokenizer(br.readLine());
    array = new int[N];
    for(int i=0;i<N;i++){
      array[i] = Integer.parseInt(st.nextToken());
    }

    Arrays.sort(array);
        
    for(int i=2;i<=N;i++){
      chooseNumber(0, 0, 0, i);
    }

    System.out.println(result);
  }
}