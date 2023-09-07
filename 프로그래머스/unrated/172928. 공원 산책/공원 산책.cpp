#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
    
    int N = park[0].length();
    int x=0, y=0;
    
    //시작점 찾기
    for(int i=0;i<park.size();i++){
        for(int j=0;j<park[0].length();j++){
            if(park[i][j] == 'S'){
                x = i;
                y = j;
                break;
            }
        }
    }
    cout<< x<<' '<<y<<'\n';
    for(int i=0;i<routes.size();i++){
        char c = routes[i][0];
        int move = routes[i][2]-'0';
        
        int xx = x, yy = y;
        int flag = 0;
        if(c == 'S'){
            for(int j=1;j<=move;j++){
                if(xx + j >= N) {
                    flag = 1;
                    break;
                }
                if(park[xx+j][y] == 'X') {
                    flag = 1;
                    break;
                }
            }
            if(flag == 0) x = xx+move;           
        }
        else if(c == 'E'){
            for(int j=1;j<=move;j++){
                if(yy + j >= N) {
                    flag = 1;
                    break;
                }
                if(park[x][yy+j] == 'X') {
                    flag = 1;
                    break;
                }
            }
            if(flag == 0) y = yy+move;           
        }
        else if(c == 'N'){
            for(int j=1;j<=move;j++){
                if(xx - j < 0 ) {
                    flag = 1;
                    break;
                }
                if(park[xx-j][y] == 'X') {
                    flag = 1;
                    break;
                }
            }
            if(flag == 0) x = xx - move;           
            
        }
        else if(c == 'W'){
            for(int j=1;j<=move;j++){
                if(yy - j < 0) {
                    flag = 1;
                    break;
                }
                if(park[x][yy-j] == 'X') {
                    flag = 1;
                    break;
                }
            }
            if(flag == 0) y = yy-move;   
        }
    }
    answer.push_back(x);
    answer.push_back(y);
    
    return answer;
}