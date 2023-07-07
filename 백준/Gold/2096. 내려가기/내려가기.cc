// 2096 내려가기

#include <iostream>

using namespace std;
int n, mini, maxi;
int arr[3], maxx[3], minn[3];
int t1, t2;

int mn(int a, int b) { // 최소 값 리턴
	if (a > b)
		return b;
	return a;
}
int mx(int a, int b) { // 최대 값 리턴
	if (a < b)
		return b;
	return a;
}

int main() {
	cin >> n;
	cin >> maxx[0] >> maxx[1] >> maxx[2];
	minn[0] = maxx[0];
	minn[1] = maxx[1];
	minn[2] = maxx[2];

	for (int i = 1; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> arr[j];
		}
		t1 = maxx[0]; t2 = maxx[2];
		maxx[0] = mx(maxx[0], maxx[1]) + arr[0];
		maxx[2] = mx(maxx[2], maxx[1]) + arr[2];
		maxx[1] = mx(mx(t1, maxx[1]), t2) + arr[1];

		t1 = minn[0]; t2 = minn[2];
		minn[0] = mn(minn[0], minn[1]) + arr[0];
		minn[2] = mn(minn[2], minn[1]) + arr[2];
		minn[1] = mn(mn(t1, minn[1]), t2) + arr[1];

	}
    
    maxi = mx(mx(maxx[0], maxx[1]), maxx[2]);
	mini = mn(mn(minn[0], minn[1]), minn[2]);
    
    cout << maxi << " " << mini << endl;
}