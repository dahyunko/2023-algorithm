#include <string>
#include <vector>

using namespace std;

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    
    //테이블 생성
    int tab[101][101];
    int c=1;
    for(int i=1;i<=rows;i++){
        for(int j=1;j<=columns;j++) tab[i][j] = c++;
    }
    
    for(int q=0;q < queries.size();q++){
        int ans = rows * columns;
        int x1 = queries[q][0], x2 = queries[q][1], y1= queries[q][2], y2 = queries[q][3];
        int temp, tmp;
        
        //위
        temp = tab[x1][x2];
        for(int j= x2;j< y2;j++){
            tmp = tab[x1][j+1];
            tab[x1][j+1] = temp;
            temp = tmp;
            ans = min(temp, ans);
        }
        //오른쪽
        for(int i= x1;i<y1;i++){
            tmp = tab[i+1][y2];
            tab[i+1][y2] = temp;
            temp = tmp;
            ans = min(temp, ans);
        }
        //아래
        for(int j = y2; j> x2;j--){
            tmp = tab[y1][j-1];
            tab[y1][j-1] = temp;
            temp = tmp;
            ans = min(temp, ans);
        }
        //왼쪽
        for(int i= y1;i>x1;i--){
            tmp = tab[i-1][x2];
            tab[i-1][x2] = temp;
            temp = tmp;
            ans = min(temp, ans);
        }
        
        answer.push_back(ans);
    }
    
    return answer;
}