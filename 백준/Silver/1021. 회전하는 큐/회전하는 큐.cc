#include <iostream>
#include <vector>
//#include<algorithm>
//#include <string>
#include <queue>

using namespace std;


int main() {
	int N, M;
	cin >> N;
	cin >> M;
	int num;
	deque<int> d;
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		d.push_back(i + 1);
	}
	int idx;
	
	while (M--) {
		cin >> num;
		for (int i = 0; d.size(); i++) {
			if (d[i] == num) {
				idx = i;
				break;
			}
		}
		if (idx < d.size() - idx) {
			while (1) {
				if (d.front() == num) {
					d.pop_front();
					break;
				}
				++cnt;
				d.push_back(d.front());
				d.pop_front();
			}
		}
		else {
			while (1) {
				if (d.front() == num) {
					d.pop_front();
					break;
				}
				++cnt;
				d.push_front(d.back());
				d.pop_back();
			}
		}
	}
		cout << cnt << endl;
	
}