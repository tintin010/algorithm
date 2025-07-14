#include <iostream>

using namespace std;

int main(){
    int n;
    int arr[501][501];

    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i; j++) cin >> arr[i][j];
    }

    for(int i = 2; i <= n; i++){
        for(int j = 1; j <= i; j++){
            if(j == 1){
                arr[i][j] += arr[i - 1][j];
            }
            else if(j == n) arr[i][j] += arr[i - 1][j - 1];
            else{
                arr[i][j] = max(arr[i][j] + arr[i - 1][j - 1], arr[i][j] + arr[i - 1][j]);
            }
        }
    }
    int mm = 0;
    for(int i = 1; i <= n; i++){
        mm = max(mm, arr[n][i]);
    }
    cout << mm << '\n';
    return 0;
}