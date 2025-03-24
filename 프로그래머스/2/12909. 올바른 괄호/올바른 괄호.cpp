#include<string>
#include <iostream>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    int t = 0;
    
    for(int i = 0; i <  s.length(); i++){
        char c = s[i];
        if(c == ')') t--;
        else if(c == '(') t++;
        
        if(t < 0) return false;
    }
    if(t > 0) answer = false;
    return answer;
}