import java.io.*;
import java.util.*;

public class Main {
  public static void main(String[] args) throws Exception{
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    String sen = br.readLine();
    Stack<Character> s = new Stack<>();
    int size = 0;

    boolean flag = true;
    for(int i=0;i<sen.length();i++){
      if(sen.charAt(i) == 'P'){
        size++;
        continue;
      }

      if(size>= 2 && i+1<sen.length() && sen.charAt(i+1) == 'P'){
        size -= 2;
      }else{
        flag = false;
        break;
      }
    }

    if(!flag) {
      System.out.println("NP");
    }else{
      if(size == 1) System.out.println("PPAP");
      else System.out.println("NP");
    }
  }
}