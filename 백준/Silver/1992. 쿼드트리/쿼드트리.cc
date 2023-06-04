//1992 쿼드 트리
/*
    처음 생각했던 풀이 방법은 Loop를 사용하여야 했기에 부자연스러움
    아래의 방법은 return을 잘 배치하였기에 Loop를 굳이 사용않고도 문제 해결 가능
    또한 bool을 이용하여 판단을 함

*/



#include <iostream>
#include <vector>
#include <string>

using namespace std;
int n;
int arr[70][70];
string str = "";


void Z(int x, int y, int pos) {
	
    if (pos == 1)
    {
        cout << arr[x][y];
        return;
    }

    bool OnlyZero, OnlyOne;
    OnlyZero = OnlyOne = true;
    for (int i = x; i < x + pos; i++)
    {
        for (int j = y; j < y + pos; j++)
        {
            if (arr[i][j] == 0) OnlyOne = false;
            if (arr[i][j] == 1) OnlyZero = false;
        }
    }

    if (OnlyZero == true)
    {
        cout << 0;
        return;
    }
    if (OnlyOne == true)
    {
        cout << 1;
        return;
    }

    cout << "(";
    Z(x, y, pos / 2);
    Z(x, y + pos / 2, pos / 2);
    Z(x + pos / 2, y, pos / 2);
    Z(x + pos / 2, y + pos / 2, pos / 2);
    cout << ")";
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		string st = "";
		cin >> st;
		for (int j = 0; j < n; j++) {
			arr[i][j] = st[j]-'0';
		}
	}
	Z(0, 0, n);
}