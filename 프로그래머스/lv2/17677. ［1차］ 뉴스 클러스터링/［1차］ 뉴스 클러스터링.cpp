#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
#include<cmath>
using namespace std;
map<string, int> m1;
map<string, int> m2;

int solution(string str1, string str2) {
    int str1_len = str1.length();
    int str2_len = str2.length();
    
    //집합 만들기
    for(int i=0;i<str1_len-1;i++){
        //영어만 인정
        if(((str1[i] >='a' && str1[i]<='z') || (str1[i] >='A' && str1[i]<='Z'))&& ((str1[i+1] >='a' && str1[i+1]<='z')|| (str1[i+1] >='A' && str1[i+1]<='Z'))){
            string s;
            s += tolower(str1[i]);
            s += tolower(str1[i+1]); 
            
            m1[s]++;
        }
    }
    //str2
    for(int i=0;i<str2_len-1;i++){
        //영어만 인정
        if((str2[i] >='a' && str2[i]<='z' || str2[i] >='A' && str2[i]<='Z')&& (str2[i+1] >='a' && str2[i+1]<='z'|| str2[i+1] >='A' && str2[i+1]<='Z')){
            string s;
            s += tolower(str2[i]);
            s += tolower(str2[i+1]);    
            m2[s]++;
        }
    }
    //교집합, 합집합
    int same=0;
    for(auto it1 : m1){
        for(auto it2 : m2){
            if(it1.first == it2.first)same+= min(it1.second, it2.second);
        }
    }
    int all =0;
    for(auto it1 : m1) all+= it1.second;
    for(auto it2 : m2) all+=it2.second;
     
    if(all == 0) return 65536;
    
    all -= same;
    cout<<same<<' '<<all<<'\n';
    double answer = (double)same/all*65536;
    return floor(answer);
}