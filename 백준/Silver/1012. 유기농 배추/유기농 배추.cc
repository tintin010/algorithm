// 유기농 배추
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <memory.h>
using namespace std;

int visit[52][52];
queue <pair<int, int>> q;

int find_bug(int col, int row, int veg) {
	int count = 0;
	int b_a = 0, b_b = 0;	// b_a : 가로위치, b_b : 세로위치
	for (int i = 0; i < veg; i++) {
		cin >> b_a >> b_b;
		visit[b_b + 1][b_a + 1] = 1;
	}
	for (int i = 1; i <= col; i++) {
		for (int j = 1; j <= row; j++) {
			if (visit[i][j] == 1) {
				q.push(make_pair(i, j));
				visit[i][j] = 0;
				count++;
				while (!q.empty()) {
					int c = q.front().first;	//col
					int r = q.front().second;	//row
					q.pop();

					if ((0 < r - 1) && (visit[c][r - 1]) == 1) {//좌
						(visit[c][r - 1]) = 0;
						q.push(make_pair(c, r - 1));
					}
					if ((r + 1 <= row) && (visit[c][r + 1]) == 1) {//우
						(visit[c][r + 1]) = 0;
						q.push(make_pair(c, r + 1));
					}
					if ((0 < c - 1) && (visit[c - 1][r]) == 1) {//상
						(visit[c - 1][r]) = 0;
						q.push(make_pair(c - 1, r));
					}
					if ((c + 1 <= col) && (visit[c + 1][r]) == 1) {//하
						(visit[c + 1][r]) = 0;
						q.push(make_pair(c + 1, r));
					}
				}
			}
		}
	}
	return count;
}

int main(void) {
	int test = 0;
	int row = 0, col = 0, cabbage = 0;	//row : 가로, col : 세로, cabbage : 양배추 개수
	cin >> test;
	
	string str = "";
	for (int i = 0; i < test; i++) {
		cin >> row >> col >> cabbage;
		memset(visit, 0, sizeof(visit));
		str += to_string(find_bug(col, row, cabbage)) + " ";
	}
	cout << str;
}