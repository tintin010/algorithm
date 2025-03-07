#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    
    int arr[rows + 1][columns + 1];
    int arrc = 1;
    for(int i = 1; i <= rows; i++){
        for(int j = 1; j <= columns; j++){
            arr[i][j] = arrc;
            arrc++;
        }
    }
    
    for(int i = 0; i < queries.size(); i++){
        int s1 = queries[i][0];
        int s2 = queries[i][1];
        int e1 = queries[i][2];
        int e2 = queries[i][3];
        
        int side = (e1 - s1 + e2 - s2) * 2;
        int cur1 = s1;
        int cur2 = s2;
        int temp1 = arr[cur1][cur2];
        int temp2 = 0;
        int answer_temp = arr[cur1][cur2];
        int k = 0;
        for(int j = 0; j < side; j++){
            if(cur1 + dy[k] >= s1 && cur1 + dy[k] <= e1 && cur2 + dx[k] >= s2 && cur2 + dx[k] <= e2){
                temp2 = arr[cur1 + dy[k]][cur2 + dx[k]];
                arr[cur1 + dy[k]][cur2 + dx[k]] = temp1;
                temp1 = temp2;
                cur1 = cur1 + dy[k];
                cur2 = cur2 + dx[k];
                // cout << "k : " << k << " : " << "temp2 : " << temp2 << "\n";
            }else{
                k++;
                temp2 = arr[cur1 + dy[k]][cur2 + dx[k]];
                arr[cur1 + dy[k]][cur2 + dx[k]] = temp1;
                temp1 = temp2;
                cur1 = cur1 + dy[k];
                cur2 = cur2 + dx[k];
            }
            if(answer_temp > temp2) answer_temp = temp2;
        }
        answer.push_back(answer_temp);
    }
    
    return answer;
}