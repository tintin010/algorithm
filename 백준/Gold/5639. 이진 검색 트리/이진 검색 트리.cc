// 5639 이진 검색 트리

#include <iostream>
#include <queue>

using namespace std;

int arr[10001];
int visit[10001];
int n = 0;


void rec(int st,int ed) {

	if (st >= ed)return;

	int i = 0;
	for (i = st + 1; i < ed; i++) if (arr[st] < arr[i])break;
	rec(st + 1, i);
	rec(i, ed);
	cout << arr[st] << endl;

}
int main() {
	int nium = 0;
	while ((cin >> nium))
		arr[n++] = nium;
	//cout << n << endl;
	rec(0, n);

}