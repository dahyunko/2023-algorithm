import java.io.*;
import java.util.*;

public class Main {
  static int N, P, result=0;

  static class Pair{
    int a, b;
    Pair(){}
    Pair(int a, int b){
      this.a = a;
      this.b = b;
    }
  }

  static void playGuitar(Stack<Pair> s, Pair v){    
    if(s.isEmpty()){
      s.add(v);
      result++;
      return;
    }

    while(!s.isEmpty()){
      Pair w = s.peek();

      if(w.b < v.b){
        s.add(v);
        result++;
        break;
      }
      else if(w.b == v.b){
        break;
      }
      else if(w.b > v.b){
        s.pop();
        result++;
      }
    }

    if(s.isEmpty()){
      s.add(v);
      result++;
    }
    else if(!s.isEmpty() && s.peek().b != v.b){
      s.add(v);
      result++;
    }

    return;
  }

  public static void main(String[] args) throws Exception{
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    StringTokenizer st = new StringTokenizer(br.readLine());
    
    Stack<Pair> s1 = new Stack<>();
    Stack<Pair> s2 = new Stack<>();
    Stack<Pair> s3 = new Stack<>();
    Stack<Pair> s4 = new Stack<>();
    Stack<Pair> s5 = new Stack<>();
    Stack<Pair> s6 = new Stack<>();

    N = Integer.parseInt(st.nextToken());
    P = Integer.parseInt(st.nextToken());

    for(int i=0;i<N;i++){
      st = new StringTokenizer(br.readLine());

      int a = Integer.parseInt(st.nextToken());
      int b = Integer.parseInt(st.nextToken());

      Pair v = new Pair(a, b);
      if(a == 1){
        playGuitar(s1, v);
      }else if(a == 2){
        playGuitar(s2, v);
      }else if(a == 3){
        playGuitar(s3, v);
      }else if(a == 4){
        playGuitar(s4, v);
      }else if(a == 5){
        playGuitar(s5, v);
      }else if(a == 6){
        playGuitar(s6, v);
      }
    }

    System.out.println(result);
  }
}