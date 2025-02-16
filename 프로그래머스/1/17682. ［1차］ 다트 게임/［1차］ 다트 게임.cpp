#include <string>
#include <cctype>
#include <iostream>

using namespace std;

int solution(string dartResult) {
    
    int temp = 0, prev_temp = 0;
    int answer = 0;
    
    for(int i = 0; i < dartResult.length(); i++){
        if(isdigit(dartResult[i])){
            if(i > 0 && isdigit(dartResult[i - 1])){
                temp = temp * 10 + dartResult[i] - '0';
                continue;
            }
            answer += prev_temp;
            prev_temp = temp;
            temp = dartResult[i] - '0';
            // return temp;
        }else if(dartResult[i] == 'D'){
            temp = temp * temp;
            // continue;
        }else if(dartResult[i] == 'T'){
            temp = temp * temp * temp;
            // continue;
        }else if(dartResult[i] == '*'){
            prev_temp *= 2;
            temp *= 2;
            // return prev_temp + temp;
            // continue;
        }else if(dartResult[i] == '#'){
            temp *= -1;
            // return temp;
            // continue;
        }
    }
    if(temp != 0) answer += temp;
    if(prev_temp != 0) answer += prev_temp;
    
    return answer;
}