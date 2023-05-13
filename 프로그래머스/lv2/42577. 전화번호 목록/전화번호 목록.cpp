#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    
    unordered_map<string, int>ht;
    
    for(auto number:phone_book) ht[number] = 1;
    for(auto number:phone_book) {
        for(int i=1;i<number.length();i++){
            if(ht.find(number.substr(0,i)) != ht.end()) return false;
        }
    }
    
    return true;
}