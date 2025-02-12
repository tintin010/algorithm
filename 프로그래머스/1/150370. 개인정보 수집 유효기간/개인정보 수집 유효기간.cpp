#include <string>
#include <vector>
#include <array>
#include <map>
#include <sstream>

using namespace std;

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    int year = stoi(today.substr(0, 4));
    int month = stoi(today.substr(5,2));
    int day = stoi(today.substr(8,2));
    
    map<char, int> termMap;
    for(int i = 0; i < terms.size(); i++){
        stringstream ss(terms[i]);
        char idx;
        int len;
        ss >> idx >> len;
        termMap[idx] = len;
    }
    for(int i = 0; i < privacies.size(); i++){
        int y = stoi(privacies[i].substr(0, 4)); 
        int m = stoi(privacies[i].substr(5, 2)); 
        int d = stoi(privacies[i].substr(8, 2));
        char a = privacies[i][11];
        // cout << y << "," << m << "," << d << "," << a << endl;
        int tmp = y * 12 * 28 + (m - 1) * 28 + d + (termMap[a] * 28 - 1);

         int total = year * 12 * 28 + (month - 1) * 28 + day;
        if(total > tmp) answer.push_back(i + 1);
        }
    
    return answer;
}