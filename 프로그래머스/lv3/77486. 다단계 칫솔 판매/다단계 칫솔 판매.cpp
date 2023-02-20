#include <string>
#include <vector>

using namespace std;

typedef pair<int, int> info;

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer;
    int N = enroll.size();
    int M = seller.size();
    vector<int>result(N, 0);
    vector<int>r_enroll(N);
    vector<int>r_referral(N, -1);
    vector<info>r_seller(M);
    
    for(int i=0;i<N;i++) r_enroll[i] = i;
    for(int i=0;i<N;i++) {
        if(referral[i] == "-") continue;
        for(int j=0;j<N;j++) {
            if(referral[i] == enroll[j])r_referral[i] = j;
        }
    }
    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            if(seller[i] == enroll[j]){
                r_seller[i].first = j;//사람
                r_seller[i].second = amount[i]*100;//금액
            }
        }
    }
    
    for(int i=0;i<M;i++){
        int idx = r_seller[i].first;    
        int pay = r_seller[i].second;    
        result[idx] += pay * 0.9;
        pay /= 10;
        
        while(r_referral[idx] != -1){
            idx = r_referral[idx];
            if(pay/10 >= 1){
                result[idx] += pay - pay/10;
                pay /=10;
            }else{
                result[idx] += pay;
                break;
            }
        }
    }
    
    for(int i=0;i<N;i++) answer.push_back(result[i]);
    
    return answer;
}