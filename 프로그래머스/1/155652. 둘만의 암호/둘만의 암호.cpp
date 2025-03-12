#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string s, string skip, int index) {
    string answer = "";
    
    int arr[26];
    
    for(int i = 0; i < 26; i++) arr[i] = 1;
    
    for(int i = 0; i < skip.length(); i++) arr[skip[i] - 'a'] = 0;
    
    for(int i = 0; i < s.length(); i++){
        int cur = s[i] - 'a';
        int move = index;
        while(move){
            cur++;
            cur = cur % 26;
            if(arr[cur]){
                move--;
            }
        }
        char c = 'a' + cur;
        answer += c;
    }    
    return answer;
}