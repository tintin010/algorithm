#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<string>> board, int h, int w) {
    int answer = 0;
    int len = board.size();
    int visit[len][len];
    int d1[4] = {0, 1, -1, 0};
    int d2[4]= {1, 0, 0, -1};
    
    for(int i = 0; i < len; i++) for(int j = 0; j < len; j++) visit[i][j] = 0;
    
    string std = board[h][w];
//     visit[h][w] = 1;
    
//     vector<pair<int, int>> v;
//     v.push_back(make_pair(h, w));
    
//     while(!v.empty()){
//         int c1 = v.front().first;
//         int c2 = v.front().second;
//         v.pop_back();
        
//         for(int i = 0; i < 4; i++){
//             if(c1 + d1[i] < 0 || c1 + d1[i] >= len || c2 + d2[i] < 0 || c2 + d2[i] >= len) continue;
//             if(!board[c1][c2].compare(board[c1 + d1[i]][c2 + d2[i]]) && visit[c1 + d1[i]][c2 + d2[i]] == 0){
//                 v.push_back(make_pair(c1 + d1[i], c2 + d2[i]));
//                 visit[c1 + d1[i]][c2 + d2[i]] = 1;
//                 answer++;
//             }
//         } 
//     }
    
    for(int i = 0; i < 4; i++){
        if(h + d1[i] < 0 || h + d1[i] >= len || w + d2[i] < 0 || w + d2[i] >= len) continue;
        if(!board[h][w].compare(board[h + d1[i]][w + d2[i]])){
            // v.push_back(make_pair(c1 + d1[i], c2 + d2[i]));
            // visit[c1 + d1[i]][c2 + d2[i]] = 1;
            answer++;
        }
    } 
    
    
    return answer;
}