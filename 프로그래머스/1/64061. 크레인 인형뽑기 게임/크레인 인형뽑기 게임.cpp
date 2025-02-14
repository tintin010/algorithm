#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    int basket[1001];
    int cnt = 0;
    int arr[31][31];
    int l = board.size();
    for(int i = 0; i < l; i++){
        for(int j = 0; j < l; j++){
            arr[i][j] = board[i][j];
        }
    }
    for(auto m : moves){
        for(int i = 0; i < l; i++){
            if(arr[i][m - 1] != 0){
                basket[cnt] = arr[i][m - 1];
                arr[i][m - 1] = 0;
                if(cnt > 0){
                    if(basket[cnt] == basket[cnt - 1]){
                        cnt--;
                        answer+=2;
                    } else cnt++;
                } else cnt++;
                break;
            }
        }
    }
    return answer;
}