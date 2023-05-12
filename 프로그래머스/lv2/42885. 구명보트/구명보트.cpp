#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    
    sort(people.begin(), people.end());
    
    int i = 0, j = people.size()-1;
    int ans = 0;
    while(i<=j){
        if(i == j) {ans++; break;}
        else if(people[i] + people[j] <= limit){
            ans++;
            i++;
            j--;
        }
        else{
            j--;
            ans++;
        }
    }
    
    answer = ans;
    return answer;
}