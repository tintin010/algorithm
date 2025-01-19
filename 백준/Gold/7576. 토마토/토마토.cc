#include <iostream>
#include <queue>
#include <string>

using namespace std;

int map[1002][1002];
queue <pair<int, int>> q;

int main(void) {
	int row = 0, col = 0; //row : 가로, col: 세로
	cin >> row >> col;
	for (int i = 1; i <= col; i++) {
		for (int j = 1; j <= row; j++) {
			cin >> map[i][j];
		}
	}
	int count = 0;
	for (int i = 1; i <= col; i++) {
		for (int j = 1; j <= row; j++) {
			if (map[i][j] == 1) {
				q.push(make_pair(i, j));
			}
		}
	}

	while (!q.empty()) {
		int size = q.size();
		count++;
		for (int i = 0; i < size; i++) {
			int c = q.front().first;	//col
			int r = q.front().second;	//row
			q.pop();

			if ((0 < r - 1) && (map[c][r - 1]) == 0) {//좌
				(map[c][r - 1]) = count;
				q.push(make_pair(c, r - 1));
			}
			if ((r + 1 <= row) && (map[c][r + 1]) == 0) {//우
				(map[c][r + 1]) = count;
				q.push(make_pair(c, r + 1));
			}
			if ((0 < c - 1) && (map[c - 1][r]) == 0) {//상
				(map[c - 1][r]) = count;
				q.push(make_pair(c - 1, r));
			}
			if ((c + 1 <= col) && (map[c + 1][r]) == 0) {//하
				(map[c + 1][r]) = count;
				q.push(make_pair(c + 1, r));
			}
		}
	}
	for (int i = 1; i <= col; i++) {
		for (int j = 1; j <= row; j++) {
			if (map[i][j] == 0) count = 0;
			//cout << map[i][j];
		}
	}
	cout << count-1 << endl;
}