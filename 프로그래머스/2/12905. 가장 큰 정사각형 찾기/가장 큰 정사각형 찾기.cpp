#include <iostream>
#include<vector>
#include <algorithm>
using namespace std;

int answer = 0;
int n, m;
int arr[1001][1001];

int search(int a, int b, vector<vector<int>> board, int len){
    int ans = 1001;
    int tx = 0, ty = 0, flag = 1;
    for(int i = a; i < a + len; i++){
        for(int j = b; j < b + len; j++){
            // arr[i][j] = 1;
            if(board[i][j] == 1){
                tx++;
            }else{
                ans = min(ans, tx);
                tx = 0;
                flag = 0;
                break;
            }
        }
        if(flag){
            ans = min(ans, tx);
            tx = 0;
        }else flag = 1;
        ty++;
        if(ty == ans) break;
    }
    
//     for(int i = a; i < a + len; i++){
//         for(int j = b; j < b + len; j++){
//             arr[i][j] = 1;
//         }
//     }
    
    ans = min(ans, ty);
    return ans;
}

int solution(vector<vector<int>> board)
{
    vector<vector<int>> dp;
    n = board.size();
    m = board[0].size();
    for(int i = 0; i < n; i++){
        vector<int> t;
        for(int j = 0; j < m; j++){
            t.push_back(board[i][j]);
        }
        dp.push_back(t);
    }
    
    for(int i = 0; i < n; i++) {
        dp[i][0] = board[i][0];
        answer = max(answer, dp[i][0]); 
    }
    for(int j = 0; j < m; j++) {
        dp[0][j] = board[0][j];
        answer = max(answer, dp[0][j]);
    }
    
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (board[i][j] == 1) {
                dp[i][j] = min({dp[i-1][j-1], dp[i-1][j], dp[i][j-1]}) + 1;
            }
            answer = max(answer, dp[i][j]);
        }
    }

    return answer * answer;
}