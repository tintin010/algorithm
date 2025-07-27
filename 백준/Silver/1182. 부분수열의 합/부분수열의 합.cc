#include <iostream>

using namespace std;

int n, m;
int ans = 0;
int arr[21];

void rec(int idx, int sum){
    if(idx == n){
        if(sum == m) ans++;
        return;
    }
    rec(idx + 1, sum + arr[idx]);
    rec(idx + 1, sum);
}

int main(){

    cin >> n >> m;

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    rec(0, 0);

    if(m == 0) ans--;

    cout << ans << '\n';
    return 0;
}