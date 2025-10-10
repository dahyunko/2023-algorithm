import java.util.*;
import java.io.*;

public class Main {

  public static void main(String[] args) throws Exception{
    
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    
    int N = Integer.parseInt(br.readLine());
    int[] arr = new int[N];
    String str = br.readLine();

    for(int i = 0;i<N;i++) {
      arr[i] = Integer.parseInt(br.readLine());
    }

    Stack<Double> s = new Stack<>();
    for(int i=0;i<str.length();i++) {
      char c = str.charAt(i);

      if(c >= 'A' && c <= 'Z') {
        int idx = c - 'A';
        s.push((double) arr[idx]);
      }
      else {
        // 연산자
        double b = s.pop();
        double a = s.pop();
        double temp = 0;
        if(c == '*'){
          temp = a * b;
        }
        else if(c == '+'){
          temp = a + b;
        }
        else if(c == '-'){
          temp = a - b;
        }
        else if(c == '/'){
          temp = a / b;
          temp = temp * 100 / 100.0;
        }

        s.push(temp);
      }
    }

    System.out.printf("%.2f",s.pop());
  }
}