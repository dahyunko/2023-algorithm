#include <string>
#include <vector>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "";
    
    int i=0, j=0, t =0;
    int size_1 = cards1.size(), size_2 = cards2.size();
    while(i<=size_1 && j<=size_2){
        int flag = 0;
        if(cards1[i] == goal[t]) {i++; t++; flag = 1;}
        if(cards2[j] == goal[t]) {j++; t++; flag = 1;}
        if(flag == 0) {break;}
    }
    
    if(t == goal.size()) answer = "Yes";
    else answer = "No";
    
    return answer;
}