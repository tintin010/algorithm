#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> ingredient) {
    int answer = 0;
    vector <int> arr = {0};
    
    for(int i = 0; i < ingredient.size(); i++){
        if(arr.back() == 1 && ingredient[i] == 2) arr.back() = 12;
        else if(arr.back() == 12 && ingredient[i] == 3) arr.back() = 123;
        else if(arr.back() == 123 && ingredient[i] == 1){
            answer++;
            arr.pop_back();
        }else arr.push_back(ingredient[i]);
    }

    return answer;
}