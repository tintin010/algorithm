// 10451 순열 바이크

#include <iostream>
#include <cstring>
#include <queue>
#include <memory.h>
using namespace std;
int t, n, ams;
int arr[1001], visit[1001];

void dfs(int k) {
		if (visit[arr[k]] == 5) {
			//cout << "visit : " << arr[k] << endl;
			ams++;
			return;
		}
		visit[arr[k]] = 1;
		dfs(arr[k]);
	
}



int main() {

	cin >> t;
	while (t--) {
		cin >> n;
		ams = 0;
		memset(visit, 0, sizeof(visit));
		for (int i = 1; i <= n; i++) cin >> arr[i];

		for (int i = 1; i <= n; i++) {
			if (!visit[i]) {
				visit[i] = 5;
				dfs(i);
			}
		}
		cout << ams << endl;

	}
}