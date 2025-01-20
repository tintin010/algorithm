//11048 이동하기
#include <iostream>
#include <algorithm>

using namespace std;

int map[1002][1002];
int c, r;
//int dx[3] = { 0,1,1 };
//int dy[3] = { 1,1,0 };


int main()
{
	cin >> c >> r;	//가로 세로 입력받기
	for (int i = 1; i <= c; i++) for (int j = 1; j <= r; j++) cin >> map[i][j];	//맵 입력
	for (int i = 1; i <= c; i++) {
		for (int j = 1; j <= r; j++) {
			map[i][j] += max(max(map[i][j - 1], map[i - 1][j]), map[i - 1][j - 1]);
		}
	}
	cout << map[c][r] << endl;
}