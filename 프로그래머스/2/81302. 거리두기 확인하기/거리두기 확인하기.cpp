#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool calc(int j, int k, int c1, int c2, char arr[5][5]){
    if(j == c1){
        if(k > c2){
            if(arr[c1][c2 + 1] == 'X') return true;
        }
        else if(k < c2){
            if(arr[j][k + 1] == 'X') return true;
        }
    }else if(k == c2){
        if(j > c1){
            if(arr[c1 + 1][c2] == 'X') return true;
        }
        else if(j < c1){
            if(arr[j + 1][k] == 'X') return true;
        }
    }else{
        if(j > c1 && k > c2){
            if(arr[j - 1][k] == 'X' && arr[j][k - 1] == 'X') return true;  // 우하단, 좌상단
        }
        else if(j > c1 && k < c2){
            if(arr[j - 1][k] == 'X' && arr[j][k + 1] == 'X') return true; // 좌하단, 우상단
        }
        else if(j < c1 && k > c2){
            if(arr[j + 1][k] == 'X' && arr[j][k - 1] == 'X') return true; // 우상단, 좌하단
        }
        else if(j < c1 && k < c2){
            if(arr[j + 1][k] == 'X' && arr[j][k + 1] == 'X') return true; // 좌상단, 우하단
        }
    }
    return false;
}

vector<int> solution(vector<vector<string>> places) {
    int d1[12] = {0, 0, 1, 1, 2, 1, 0, 0, -1, -1, -2, -1};
    int d2[12] = {1, 2, 1, 0, 0, -1, -1, -2, -1, 0, 0, 1};
    
    
    vector<int> answer;
    for(int i = 0; i < 5; i++){
        char arr[5][5];
        int flag = 1;
        for(int j = 0; j < 5; j++) for(int k = 0; k < 5; k++) arr[j][k] = places[i][j][k];
        for(int j = 0; j < 5 && flag; j++){
            for(int k = 0; k < 5 && flag; k++){
                if(arr[j][k] != 'P') continue;
                for(int l = 0; l < 12 && flag; l++){
                    int c1 = j + d1[l];
                    int c2 = k + d2[l];
                    if(c1 < 0 || c1 >= 5 || c2 < 0 || c2 >= 5) continue;
                    if(arr[c1][c2] == 'P'){
                        if(calc(j, k, c1, c2, arr)) continue;
                        else{
                            answer.push_back(0);
                            flag = 0;
                            break;
                        }
                    }
                    
                }
            }
        }
        if(flag) answer.push_back(1);
    }
    return answer;
}