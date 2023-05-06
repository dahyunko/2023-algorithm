#include <string>
#include <vector>
#include <sstream>

using namespace std;

vector<string> split(string input, char delimiter){
    vector<string>result;
    stringstream mystream(input);
    string splitdata;
    while(getline(mystream, splitdata, delimiter)) result.push_back(splitdata);
    return result;
}

string solution(string s) {
    string answer = "";
    
    bool flag = true;
    for(int i=0;i<s.length();i++){
        if(s[i] == ' ') flag = true;
        else {
            if(flag){
                if(s[i]>='a' && s[i]<='z') s[i] = s[i]-'a'+'A';
                flag = false;
            }else{
                if(s[i]>='A' && s[i]<='Z') s[i] = s[i]-'A'+'a';
            }
        }        
    }
    answer = s;
    /*
    vector<string>A = split(s, ' ');
    
    for(int i=0;i<A.size();i++){
        for(int j=0;j<A[i].length();j++){
            if(j == 0 && A[i][j]>='a' && A[i][j] <='z'){
                A[i][j] = A[i][j]-'a'+'A';
            }
            else if(A[i][j] >='A' && A[i][j] <='Z'){
                A[i][j] = A[i][j]-'A'+'a'; 
            }
            answer.push_back(A[i][j]);
        } 
        if(A.size()-1 > i) answer.push_back(' ');
    }
    */
    return answer;
}