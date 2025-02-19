#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    
    int arr[9];
    for(int i = 0; i < 8; i++) arr[i] = 0;
    map<char, int> mbti;
    
    mbti['R'] = 0;
    mbti['T'] = 1;
    mbti['C'] = 2;
    mbti['F'] = 3;
    mbti['J'] = 4;
    mbti['M'] = 5;
    mbti['A'] = 6;
    mbti['N'] = 7;
    
    for(int i = 0; i < survey.size(); i++){
        cout << survey[i] << " : " << mbti[survey[i][0]] << " : " << mbti[survey[i][1]] << "\n";
        if(choices[i] > 4){
            arr[mbti[survey[i][1]]] += choices[i] - 4;
            cout << mbti[survey[i][1]] << " : " << arr[mbti[survey[i][1]]] << '\n';
        }else if(choices[i] < 4){
            arr[mbti[survey[i][0]]] += 4 - choices[i];
            cout << mbti[survey[i][1]] << " : " << arr[mbti[survey[i][1]]] << '\n';
        }
    }
    if(arr[mbti['R']] >= arr[mbti['T']]) answer += "R";
    else answer += "T";
    
    if(arr[mbti['C']] >= arr[mbti['F']]) answer += "C";
    else answer += "F";
    
    if(arr[mbti['J']] >= arr[mbti['M']]) answer += "J";
    else answer += "M";
    
    if(arr[mbti['A']] >= arr[mbti['N']]) answer += "A";
    else answer += "N";
    
    // cout << mbti['J'] << '\n';
    
    
    return answer;
}