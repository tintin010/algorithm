#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int a[51];
    int b[51];
    vector <int> aa;
    vector <int> bb;
    int n;
    
    cin >> n;

    for(int i = 0; i < n; i++){
        int t;
        cin >> t;
        aa.push_back(t);
    }

    for(int i = 0; i < n; i++){
        int t;
        cin >> t;
        bb.push_back(t);
    }

    sort(aa.begin(), aa.end());
    sort(bb.rbegin(), bb.rend());

    // for(int i = 0; i < n; i++) cin >> a[i];
    // for(int i = 0; i < n; i++) cin >> b[i];

    // sort(a, a + n);
    // sort(b, b + n, greater<int>());

    int ans = 0;

    for(int i = 0; i < n; i++){
        ans += aa[i] * bb[i];
    }

    cout << ans << '\n';
    return 0;

}