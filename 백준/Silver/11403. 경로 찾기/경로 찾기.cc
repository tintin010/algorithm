//11403 경로 찾기
//플로이드 - 워셜 알고리즘
#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int n;
int arr[101][101];

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++)cin >> arr[i][j];
	for (int k = 1; k <= n; k++){
		for (int j = 1; j <= n; j++) {
			for (int i = 1; i <= n; i++) {
				if (arr[i][k] == 1 && arr[k][j] == 1)arr[i][j] = 1;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
}