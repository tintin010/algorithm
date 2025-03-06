#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string s) {
    int answer = 0;
    int len = s.length();
    
    while(len > 1){
        // cout << "len : " << len << "\n";
        char first = s[0];
        int cnt = 1;
        int oth = 0;
        int idx = 1;
        while(cnt != oth){
            if(idx == len) return answer + 1;
            if(s[idx] == first) cnt++;
            else oth++;
            idx++;
        }
        int sub = cnt + oth;
        s = s.substr(sub, len - sub);
        len -= sub;
        answer++;
    }
    if(len == 1) answer++;
    
    return answer;
}