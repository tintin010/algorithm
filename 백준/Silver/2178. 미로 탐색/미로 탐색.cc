#include <iostream>
#include <queue>
using namespace std;

int visited[102][102];
int map[102][102];
queue <pair<int, int>> q;

int main(void) {
	int a, b = 0;
	cin >> a >> b;
	cin.ignore();
	for (int i = 1; i <= a; i++) {
		string str;
		cin >> str;
		for (int j = 1; j <= b; j++) {
			
			visited[i][j] = str[j - 1] - '0';
		}
	}
	q.push(make_pair(1, 1));
	visited[1][1] = 0;
	map[1][1] = 1;
	while (!q.empty()) {
		int size = q.size();
		int c = q.front().first;	//col
		int r = q.front().second;	//row


		q.pop();

		if ((0 < r - 1) && (visited[c][r - 1]) == 1) {//좌
			(visited[c][r - 1]) = 0;
			q.push(make_pair(c, r - 1));
			map[c][r - 1] = map[c][r] + 1;
		}
		if ((r + 1 <= b) && (visited[c][r + 1]) == 1) {//우
			(visited[c][r + 1]) = 0;
			q.push(make_pair(c, r + 1));
			map[c][r + 1] = map[c][r] + 1;
			if (c == a && r + 1 == b) {
				while (!q.empty())q.pop();
				break;
			}
		}
		if ((0 < c - 1) && (visited[c-1][r]) == 1) {//상
			(visited[c - 1][r]) = 0;
			q.push(make_pair(c - 1, r));
			map[c-1][r] = map[c][r] + 1;
			
		}
		if ((c + 1 <= a) && (visited[c + 1][r]) == 1) {//하
			(visited[c + 1][r]) = 0;
			q.push(make_pair(c + 1, r));
			map[c+1][r] = map[c][r] + 1;
			if (c + 1 == a && r == b) {
				while (!q.empty())q.pop();
				break;
			}
		}
	}
	cout << map[a][b];
}