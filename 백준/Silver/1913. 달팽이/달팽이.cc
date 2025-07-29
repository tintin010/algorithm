#include <iostream>

using namespace std;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int arr[1000][1000];
int vis[1000][1000];
int n, m, dir, rety, retx, y, x;
int cur;

int main(){

    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++){
        arr[i][j] = 0;
    }
    cin >> n >> m;

    for(int i = n * n; i > 0; i--){
        arr[y][x] = i;
        if(i == m){rety = y + 1; retx = x + 1;}
        if(y + dy[dir] < 0 || y + dy[dir] >= n || x + dx[dir] < 0 || x + dx[dir] >= n || arr[y + dy[dir]][x + dx[dir]] != 0){
            dir = (dir + 1) % 4;
        }
        y = y + dy[dir];
        x = x + dx[dir];
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << arr[i][j] << " ";
        }
        cout <<"\n";
    }
    cout << rety << " " << retx << "\n";
    return 0;
}