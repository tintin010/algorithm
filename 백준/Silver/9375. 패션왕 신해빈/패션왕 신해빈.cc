//9375 신해빈

#include <iostream>
#include <map>
#include <string>

using namespace std;
int n, t;
string ip, id;


int main() {
	cin >> t;
	while (t--) {
		map<string, int>m;
		cin >> n;
		while (n--) {
			cin >> ip >> id;
			if (m.find(id) == m.end()) {
				m.insert({ id,1 });
			}
			else {
				m[id]++;
			}
		}
		int ans = 1;
		for (auto i : m) {
			ans *= (i.second + 1);
		}
		ans -= 1;
		cout << ans << endl;
	}
	
}