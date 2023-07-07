// 16953 a -> b

#include <iostream>
#include <queue>
#include <set>

using namespace std;

typedef long long ll;

ll a, b;
int mini = 10000;



void bfs(ll a,int cnt) {
	if (a > b) return;
	if (a == b) {
		mini = min(mini, cnt);
	}
	bfs(a * 2, cnt + 1);
	bfs(a * 10 + 1, cnt + 1);

}

int main() {
	cin >> a >> b;
	bfs(a, 1);
	if (mini == 10000)cout << "-1";
	else cout << mini;
}
