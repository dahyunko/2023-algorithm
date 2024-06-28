import java.io.*;
import java.util.*;
public class Main {
    static int N;
    static List<Info> flower = new ArrayList<>();
    static class Info implements Comparable<Info>{
        int s, e;

        Info(int s, int e){
            this.s = s;
            this.e = e;
        }

        @Override
        public int compareTo(Info o){
            if(o.e == this.e) return this.s - o.s;
            return o.e - this.e;
        }

        public String toString(){
            return "[s: " + s + ", e: " + e + "]\n";
        }
    }

    public static void main(String[] str) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        N = Integer.parseInt(br.readLine());
        StringTokenizer st = null;

        int ss = 10000, ee = 0;
        for(int i=0;i<N;i++){
            st = new StringTokenizer(br.readLine());
            int sm = Integer.parseInt(st.nextToken());
            int sd = Integer.parseInt(st.nextToken());
            int em = Integer.parseInt(st.nextToken());
            int ed = Integer.parseInt(st.nextToken());

            if(em < 3 || sm > 11) continue;
            int s = sm*100 +  sd;
            int e = em*100 +  ed;

            ss = Math.min(ss, s);
            ee = Math.max(ee, e);

            flower.add(new Info(s, e));
        }

        // 조건을 만족할 수 없음
        if(ss > 301 || ee < 1201) {
            System.out.println(0);
            return;
        }
        Collections.sort(flower);

        //System.out.println(flower.toString());

        int cnt = 1;

        int prev = 0, now, end;
        for(int i=1;i<flower.size();i++){
            now = i;
            //System.out.println("now: " + now + " , prev: " + prev);
            boolean isFined = false;
            int temp = prev;
            while(now < flower.size()){
                if(flower.get(prev).s > flower.get(now).e){
                    break;
                }

                // 시작 날짜가 더 작아야함
                if(flower.get(temp).s > flower.get(now).s){
                    temp = now;
                    isFined = true;
                }
                if(flower.get(now).s <= 301) break;
                now++;
            }

            if(!isFined) break;
            //System.out.println(flower.get(temp).toString());
            if(prev == 0 && temp != 0 && flower.get(temp).e > 1130){
                cnt--;
            }
            i = temp;
            prev = temp;
            cnt++;
            if(flower.get(prev).s <= 301) break;
        }

        if(flower.get(prev).s > 301){
            System.out.println(0);
        }else{
            System.out.println(cnt);
        }
    }
}

/*
3
1 1 11 30
11 10 12 5
3 1 12 1
* */