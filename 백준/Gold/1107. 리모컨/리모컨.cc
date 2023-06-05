//리모콘 1107

#include <iostream>
#include <string>


using namespace std;
int n, m, mini;
int arr[11];
int broken[11];	//고장난 버튼 배열
int num[6];
int num_but[6];
int mark = 0;
int st_but = 100;

bool cal(int a) {
	string st = to_string(a);
	for (int i = 0; i < st.length(); i++) {
		if (broken[st[i] - '0']) return false;
	}
	return true;
	 
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int temp = 0;
		cin >> temp;
		broken[temp] = 1;
	}

	mini = abs(n - 100);
	for (int i = 0; i < 1000000; i++)
	{/*주어지는 버튼의 제한은 50만이지만 실제로 100만 이상의 수까지 나타낼 수 있음
	즉, 50만을 기준으로 높은 값에서 내려올 수 있음*/

		if (cal(i)) {
			int t = to_string(i).length() + abs(n - i);
			mini = min(mini, t);
		}
	}
	cout << mini << endl;
}