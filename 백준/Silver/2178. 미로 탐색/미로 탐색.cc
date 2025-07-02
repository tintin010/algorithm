#include <iostream>
#include <queue>
#include <string>

using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int arr[101][101];
int visited[101][101];
int answer = 0;
int n, m;
queue <pair<int, int>> q;


void bfs(int i, int j){
    visited[i][j] = 1;
    q.push({i, j});

    while(q.size()){
        int x = q.front().first;
        int y = q.front().second;

        if(x == (n - 1) && y == (m - 1)){
            cout << visited[x][y] << '\n';
            return;
        }

        q.pop();
        for(int k = 0; k < 4; k++){
            int cx = dx[k] + x;
            int cy = dy[k] + y;
            if(cx < 0 || cx >= n || cy < 0 || cy >= m || visited[cx][cy] >= 1 || arr[cx][cy] == 0) continue;

            visited[cx][cy] = visited[x][y] + 1;
            q.push({cx, cy});
        }
    }
}

int main(){
    cin >> n >> m;

    for(int i = 0; i < n; i++){
        string str;
        cin >>str;
        for(int j = 0; j < m; j++){
            arr[i][j] = str[j] - '0';
        }
    }
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++) visited[i][j] = 0;
    bfs(0, 0);
    return 0;
}