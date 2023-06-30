//2751 수 정렬하기
#include <iostream>
#include <algorithm>

using namespace std;
int n, a;
int arr[1000001];

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
    
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	for (int i = 0; i < n;i++) {
		cout << arr[i] << '\n';
	}
}