//11725 트리의 부모 찾기

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
#define MAX 100001
int visit[MAX];
int n, a, b;
int arr[MAX];
vector <int>v[MAX];

void dfs(int k) {
	visit[k] = 1;
	for (int i = 0; i < v[k].size(); i++) {
		int temp = v[k][i];
		if (!visit[temp]) {
			arr[temp] = k;
			dfs(temp);
		}
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	dfs(1);
	for (int i = 2; i <= n; i++)cout << arr[i] << '\n';
}