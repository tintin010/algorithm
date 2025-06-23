#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int arr[2][100001];
    int res[2][100001];
    int tc, n;
    cin >> tc;
    for(int i = 0; i < tc; i++){
        cin >> n;
        for(int j = 0; j < 2; j++){
            for(int k = 0; k < n; k++){
                cin >> arr[j][k];
                res[j][k] = 0;
            }
        }
        res[0][0] = arr[0][0];
        res[1][0] = arr[1][0];

        res[0][1] = arr[1][0] + arr[0][1];
        res[1][1] = arr[0][0] + arr[1][1];

        for(int j = 2; j < n; j++){
            res[0][j] = max(res[1][j - 1] + arr[0][j], res[1][j - 2] + arr[0][j]);
            res[1][j] = max(res[0][j - 1] + arr[1][j], res[0][j - 2] + arr[1][j]);
        }

        int answer = max(res[0][n - 1], res[1][n - 1]);
        cout << answer << '\n';
    }
}