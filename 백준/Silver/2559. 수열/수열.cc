#include <iostream>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    int arr[100001];
    int ans = -100 * m;
    
    for(int i = 0; i < n; i++) cin >> arr[i];

    int init = 0;
    for(int i = 0; i < m; i++) init += arr[i];
    ans = max(init, ans);

    for(int i = m; i < n; i++){
        init = init - arr[i - m] + arr[i];
        ans = max(init, ans);
    }

    cout << ans << '\n';
}