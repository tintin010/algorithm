//15686 치킨 배달

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n, m, cn, anss;
int mapp[51][51];
int selectt[15];
void sc(int, int);
int cd();

vector<pair<int, int>> h, c, v;

int cd()
{
    int ss = 0;
    for (int i = 0; i < h.size(); i++)
    {
        int x = h[i].first;
        int y = h[i].second;
        int d = 99999999;

        for (int j = 0; j < v.size(); j++)
        {
            int xx = v[j].first;
            int yy = v[j].second;
            int dis = abs(xx - x) + abs(yy - y);

            d = min(d, dis);
        }
        ss = ss + d;
    }
    return ss;
}

void sc(int idx, int cnt)
{
    if (cnt == m)
    {
        anss = min(anss, cd());
        return;
    }

    for (int i = idx; i < cn; i++)
    {
        if (selectt[i] == 1) continue;
        selectt[i] = 1;
        v.push_back(c[i]);
        sc(i, cnt + 1);
        selectt[i] = false;
        v.pop_back();
    }
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++){
			cin >> mapp[i][j];
			if (mapp[i][j] == 1) h.push_back({ i, j });
			if (mapp[i][j] == 2) c.push_back({ i, j });
		}
	}
    anss = 99999999;
	cn = c.size();
    sc(0, 0);
    cout << anss;

}