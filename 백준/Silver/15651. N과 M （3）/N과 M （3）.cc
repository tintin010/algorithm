//15651 n과 m  - 3

#include <iostream>
#define MAX 9
using namespace std;
int n, m;
int arr[MAX], visit[MAX];

void dfs(int k) {
	if (k == m) {
		for (int i = 0; i < m; i++) cout << arr[i] << " ";
		cout << '\n';
		return;
	}
	else {
		for (int i = 1; i <= n; i++) {
			arr[k] = i;
			dfs(k + 1);
		}
	}
}

int main() {
	cin >> n >> m;
	dfs(0);
}