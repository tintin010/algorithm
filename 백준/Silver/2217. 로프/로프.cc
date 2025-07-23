#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){

    int n;
    vector<int> arr;
    int min = 100000;

    cin >> n;

    for(int i = 0; i < n; i++){
        int t;
        cin >> t;
        arr.push_back(t);
    }

    sort(arr.begin(), arr.end());

    int ans = 0;

    for(int i = n - 1; i >= 0; i--){
        int cnt = n - i;
        ans = max(ans, cnt * arr[i]);
    }

    cout << ans << '\n';

}