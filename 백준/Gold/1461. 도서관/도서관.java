import java.io.*;
import java.util.*;

public class Main {
  static int N, M;

  static int comeback(List<Integer> arr){
    int idx = arr.size() - 1;
    int sumDis = 0;

    while(idx >= 0){
      sumDis += arr.get(idx) * 2;
      idx -= M;
    }

    return sumDis;
  }

  public static void main(String[] args) throws Exception{
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());
    
    int result = 0;
    N = Integer.parseInt(st.nextToken());
    M = Integer.parseInt(st.nextToken());

    List<Integer> arrP = new ArrayList<>();
    List<Integer> arrN = new ArrayList<>();

    st = new StringTokenizer(br.readLine());
    for(int i=0;i<N;i++) {
      int now = Integer.parseInt(st.nextToken());
      if(now > 0) arrP.add(now);
      else arrN.add(now * (-1));
    }

    Collections.sort(arrP);
    Collections.sort(arrN);

    result = comeback(arrN) + comeback(arrP);

    if(arrP.size() == 0) arrP.add(0);
    if(arrN.size() == 0) arrN.add(0);

    result -= Math.max(arrP.get(arrP.size()-1), arrN.get(arrN.size()-1));
    System.out.println(result);
  } 
  
}