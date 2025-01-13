#include <iostream>
using namespace std;



int main()
{
#pragma region 브루트 포스
	// 가능한 모든 경우의 수를 탐색하면서
	// 결과를 도출해내는 알고리즘입니다.

	/// 비밀번호 000 ~ 999

	int password[3] = { 1, 2, 3 };

	for (int i = 0; i <= 9; i++)
	{
		for (int j = 0; j <= 9; j++)
		{
			for (int k = 0; k <= 9; k++)
			{
				if (password[0] == i && password[1] == j && password[2] == k)
				{
					cout << i << " " << j << " " << k << endl;
					cout << "비밀번호 해제" << endl;

					break;
				}
			}
		}
	}

#pragma endregion


	return 0;
}
