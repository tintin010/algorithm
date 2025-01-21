#include <iostream>

#include <vector>

#include <queue>

#include <functional>

using namespace std;



int main(void)

{

    ios_base::sync_with_stdio(0);

    cin.tie(0);

    int N;

    cin >> N;



    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    for (int i = 0; i < N; i++)

    {

        int num;

        cin >> num;



        if (!num && pq.empty())

            cout << 0 << "\n";

        else if (!num)

        {

            cout << pq.top().second << "\n";

            pq.pop();

        }

        else {

            pq.push({ abs(num), num });
        }

            

    }

    return 0;

}