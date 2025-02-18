#include <string>
#include <vector>
#include <sstream>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
    char map [51][51];
    int col = park.size();
    int row = park[0].size();
    int cur_x = 0;
    int cur_y = 0;
    
    for(int i = 0; i < col; i++) {
        for(int j = 0; j < row; j++){
            map[i][j] = park[i][j];
            if(park[i][j] == 'S'){
                cur_x = j;
                cur_y = i;
                cout << "cur_x : " << cur_x << " :: cur_y : " << cur_y << "\n";
            }
        }
    }
        
    
    for(int i = 0; i < routes.size(); i++){
        stringstream ss(routes[i]);
        char dir;
        int len;
        ss >> dir >> len;
        int temp_x = cur_x;
        int temp_y = cur_y;
        cout << "dir : " << dir << " :: len : " << len << "\n";
        if(dir == 'E'){
            cout << "E" << "\n";
            for(int j = 0; j < len; j++){
                cur_x = cur_x + 1;
                if(map[cur_y][cur_x] == 'S' || map[cur_y][cur_x] == 'O') continue;
                else{
                    cur_x = temp_x;
                    break;
                }
            }
            // cur_x +=len;
            cout << "X : " << cur_x << ", Y : " << cur_y << "\n";
        }else if(dir == 'W'){
            cout << "W" << "\n";
            for(int j = 0; j < len; j++){
                cur_x--;
                if(map[cur_y][cur_x] == 'S' || map[cur_y][cur_x] == 'O') continue;
                else{
                    cur_x = temp_x;
                    break;
                }
            }
            // cur_x -= len;
            cout << "X : " << cur_x << ", Y : " << cur_y << "\n";
        }else if(dir == 'S'){
            cout << "S" << "\n";
            for(int j = 0; j < len; j++){
                cur_y++;
                if(map[cur_y][cur_x] == 'S' || map[cur_y][cur_x] == 'O') continue;
                else{
                    cur_y = temp_y;
                    break;
                }
            }
            // cur_y += len;
            cout << "X : " << cur_x << ", Y : " << cur_y << "\n";
        }else if(dir == 'N'){
            cout << "N" << "\n";
            for(int j = 0; j < len; j++){
                cur_y--;
                if(map[cur_y][cur_x] == 'S' || map[cur_y][cur_x] == 'O') continue;
                else{
                    // cur_y = temp_y;
                    cur_y = temp_y;
                    break;
                }
            }
            cout << "X : " << cur_x << ", Y : " << cur_y << "\n";
        }        
    }
    answer.push_back(cur_y);
    answer.push_back(cur_x);
    return answer;
}