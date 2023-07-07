// 15657 n m - 9

#include <iostream>
#include <algorithm>
#include <set>
#include <string>

#define MAX 9
using namespace std;
int n, m;
int arr[MAX], ma[MAX];

void bfs(int c, int k) {
	if(c==m){
		for (int i = 0; i < m; i++) cout << arr[i] << " ";
		cout << '\n';
		return;
	}
	for (int i = k; i < n; i++) {
		arr[c] = ma[i];
		bfs(c + 1, i);
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++)cin >> ma[i];
	sort(ma, ma + n);
	bfs(0, 0);
}