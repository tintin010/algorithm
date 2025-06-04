#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(){
    int n = 0, k = 0;
    int result = 1;
    cin >> n >> k;
    int arr[102][102];
    int dx[4] = {0, 1, 0, -1};  // 우 하 좌 상 시계방향향
    int dy[4] = {1, 0, -1, 0};
    vector <pair<int, char>> command;
    queue <pair<int, int>> move;
    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) arr[i][j] = 0;
    int a, b;
    for(int i = 0; i < k; i++){
        cin >> a >> b;
        arr[a][b] = 1;
    }
    int l;
    cin >> l;
    for(int i = 0; i < l; i++){
        int a; char c;
        cin >> a >> c;
        command.push_back({a, c});
    }

    move.push({1, 1});
    // result++;
    arr[1][1] = 10;
    int st_x = 1;
    int st_y = 1;
    int d = 0;
    int pastTime = 0;

    for(int i = 0; i < command.size(); i++){
        int time = command[i].first;
        char t = command[i].second;
        for(int j = 0; j < time - pastTime; j++){
            
            if(st_x + dx[d] > n || st_x + dx[d] < 1 || st_y + dy[d] > n || st_y + dy[d] < 1 || arr[st_x + dx[d]][st_y + dy[d]] == 10){
                cout << result << '\n';
                return 0;
            }
            if(arr[st_x + dx[d]][st_y + dy[d]] != 1){
                int tx = move.front().first;
                int ty = move.front().second;
                move.pop();
                arr[tx][ty] = 0;
            }
            // cout << st_x + dx[d] << " :: " << st_y + dy[d] << "\n";
            arr[st_x + dx[d]][st_y + dy[d]] = 10;
            move.push({st_x + dx[d], st_y + dy[d]});
            result++;
            st_x = st_x + dx[d];
            st_y = st_y + dy[d];
        }
        if(t == 'D'){
            d = (d + 1) % 4;
        }else{
            if(d == 0){
                d = 3;
            }else{
                d -= 1;
            }
        }
        pastTime = time;
    }

    while(true){
        if(st_x + dx[d] > n || st_x + dx[d] < 1 || st_y + dy[d] > n || st_y + dy[d] < 1 || arr[st_x + dx[d]][st_y + dy[d]] == 10){
            cout << result << '\n';
            return 0;
        }
        if(arr[st_x + dx[d]][st_y + dy[d]] != 1){
            int tx = move.front().first;
            int ty = move.front().second;
            move.pop();
            arr[tx][ty] = 0;
        }
        arr[st_x + dx[d]][st_y + dy[d]] = 10;
        move.push({st_x + dx[d], st_y + dy[d]});
        result++;
        st_x = st_x + dx[d];
        st_y = st_y + dy[d];
    }
}