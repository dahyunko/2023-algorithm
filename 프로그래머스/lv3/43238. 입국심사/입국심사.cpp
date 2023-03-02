#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;
typedef long long ll;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    
    int t = times.size();
    sort(times.begin(), times.end());
    
    ll i=1, j = times[0]* static_cast<ll>(n);
    while(i<=j){
        auto mid = (i+j)/2;
        ll people=0;
        for(int p=0;p<t;p++) {
            auto value = mid/times[p]; 
            people += value;
        }
        
        if(people >= n){
            answer = mid;
            j = mid-1;
        }
        else i = mid+1;
    }
    
    return answer;
}