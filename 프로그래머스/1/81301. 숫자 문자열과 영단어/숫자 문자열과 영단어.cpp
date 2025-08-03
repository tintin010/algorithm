#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

int solution(string s) {
    map<string, string> nm = {
            {"zero", "0"}, {"one", "1"}, {"two", "2"},
            {"three", "3"}, {"four", "4"}, {"five", "5"},
            {"six", "6"}, {"seven", "7"}, {"eight", "8"}, {"nine", "9"}};
    string answer = "";
    string temp = "";
    
    for (char ch : s) {
        if (isdigit(ch)) {
            answer += ch;
        } else {
            temp += ch;
            if (nm.count(temp)) {
                answer += nm[temp]; 
                temp = ""; 
            }
        }
    }
    int fin = stoi(answer);
    return fin;
}