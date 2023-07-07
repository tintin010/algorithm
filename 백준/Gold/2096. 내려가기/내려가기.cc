#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int mn(int a, int b) {
    if (a > b)
        return b;
    return a;
}

int mx(int a, int b) {
    if (a < b)
        return b;
    return a;
}

int main() {
    int n;
    cin >> n;

    int maxx[3], minn[3];
    cin >> maxx[0] >> maxx[1] >> maxx[2];
    minn[0] = maxx[0];
    minn[1] = maxx[1];
    minn[2] = maxx[2];

    int arr[3];
    int t1, t2;

    for (int i = 1; i < n; i++) {
        cin >> arr[0] >> arr[1] >> arr[2];
        t1 = maxx[0]; t2 = maxx[2];
        maxx[0] = mx(maxx[0], maxx[1]) + arr[0];
        maxx[2] = mx(maxx[2], maxx[1]) + arr[2];
        maxx[1] = mx(mx(t1, maxx[1]), t2) + arr[1];

        t1 = minn[0]; t2 = minn[2];
        minn[0] = mn(minn[0], minn[1]) + arr[0];
        minn[2] = mn(minn[2], minn[1]) + arr[2];
        minn[1] = mn(mn(t1, minn[1]), t2) + arr[1];
    }

    int maxi = mx(mx(maxx[0], maxx[1]), maxx[2]);
    int mini = mn(mn(minn[0], minn[1]), minn[2]);
    cout << maxi << " " << mini << endl;
    return 0;
}
