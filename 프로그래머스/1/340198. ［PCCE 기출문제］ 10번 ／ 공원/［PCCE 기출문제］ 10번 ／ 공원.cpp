#include <string>
#include <vector>
#include <cctype>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> mats, vector<vector<string>> park) {
    int answer = 0;
    int c = park.size();
    int r = park[0].size();
    
    for(int i = 0; i < c; i++){
        for(int j = 0; j < r; j++){
            if(!isalpha(park[i][j][0])){
                int t = 1;
                bool flag = true;
                while(flag){
                    if (i + t > c || j + t > r) {
                        break;
                    }
                    for(int k = i; k < t + i && flag; k++){
                        for(int l = j; l < t + j; l++){
                            if (isalpha(park[k][l][0])){
                                flag = false;
                                break;
                            }
                        }
                    }
                    if(flag)
                        t++;
                    else
                        break;
                }
                answer = max(answer, t - 1);
            }
        }
    }
    int fin = 0;
    for(int i = 0; i < mats.size(); i++){
        if(answer >= mats[i]){
            fin = max(fin, mats[i]);
        }
    }
    if(fin == 0)return -1;
    
    return fin;
}