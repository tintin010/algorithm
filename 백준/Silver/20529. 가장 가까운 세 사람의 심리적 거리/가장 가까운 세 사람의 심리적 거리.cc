#include <iostream>
#include <string>
#include <vector>

using namespace std;

int compareMBTI(string mbti1, string mbti2, string mbti3)
{
	int res = 0;

	// MBTI 4가지 척도를 비교하면서 다를 경우 거리 1씩 더하기
	for (int i = 0; i < 4; i++)
	{
		if (mbti1[i] != mbti2[i]) res++;
		if (mbti1[i] != mbti3[i]) res++;
		if (mbti2[i] != mbti3[i]) res++;
	}

	return res;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// 테스트 케이스 입력
	int T;
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		// 학생 수 입력
		int N;
		cin >> N;

		// MBTI 입력
		vector<string> input_mbti(N);
		for (int j = 0; j < N; j++)
			cin >> input_mbti[j];

		// 만약 학생 수가 33명 이상이면 MBTI 같은 사람이 최소 3명 이상 있으므로, 0을 반환
		if (N >= 33)
		{
			cout << 0 << '\n';
			continue;
		}

		int min_dist = 123456789;

		// 학생 3명 선택
		for (int j = 0; j < N - 2; j++)
			for (int k = j + 1; k < N - 1; k++)
				for (int l = k + 1; l < N; l++)
					min_dist = min(min_dist, compareMBTI(input_mbti[j], input_mbti[k], input_mbti[l])); // 선택한 3명의 MBTI 비교하여 심리적인 거리 계산

		// 가장 가까운 세 학생의 심리적인 거리 출력
		cout << min_dist << "\n";
	}

	return 0;
}