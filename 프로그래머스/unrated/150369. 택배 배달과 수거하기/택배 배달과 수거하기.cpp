#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    ll answer = -1;   

    ll time=0;
    int j = n-1;

    //for(int j=n-1;j>=0;j--){
    while(j >= 0){
        int bag = cap;
        //배달
        if(deliveries[j] == 0 && pickups[j] == 0){
            j--;
            continue;
        } 
        time += (j+1) * 2;
        
        for(int i=j;i>=0;i--){
            if(deliveries[i] == 0) continue;
            if(bag == 0) break;
            if(deliveries[i] <= bag){
                bag -= deliveries[i];
                deliveries[i] = 0;
            }
            else if(bag < deliveries[i]){
                deliveries[i] -= bag;
                bag = 0;
            }
        }
        if(bag > 0) bag = 0;
        
        //수거
        for(int i=j;i>=0;i--){
            if(pickups[i] == 0) continue;
            if(bag == cap) break;
            if(pickups[i] <= cap - bag){
                bag += pickups[i];
                pickups[i] = 0;
            }
            else if(pickups[i] > cap - bag){
                pickups[i] -= (cap - bag);
                bag = cap;
            }
        } 
    }
    
    answer = time;
    return answer;
}