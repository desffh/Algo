#include <iostream>
using namespace std;

int Euclid(int x, int y)
{
	// 1. 두 개의 자연수x, y가 있습니다.
	//	  그리고 x와 y로 나눈 나머지를 R 이라고 합니다.

	// 2. R이 0이라면, x와 y의 최대공약수 y가 됩니다.

	// 3. R이 0이 아니라면, x와 y의 최대공약수는 y와 R의
	//	  최대 공약수와 같기 때문에, x에는 y 그리고 y에는 R을 대입한 후
	//	  1번으로 돌아갑니다.

	if (y == 0)
	{
		return x;
	}
	else
	{
		return Euclid(y, x % y);
	}
}



int main()
{
#pragma region 최대공약수 구하기
	//// 시간복잡도 O(N)
	//int x = 36;
	//int y = 18;
	//
	//int num = 0;
	//
	//for (int i = 1; i <= x && i <= y; i++)
	//{
	//	if (x % i == 0 && y % i == 0)
	//	{
	//		num = i;
	//	}
	//}
	//
	//cout << "최대공약수의 값 : " << num << endl;

#pragma endregion

#pragma region 유클리드 호제법
	// 2개의 자연수 또는 정식의 최대 공약수를 구하는 방식으로
	// 두 수가 서로 상대방 수를 나누어서 원하는 수를 얻어내는 알고리즘입니다.

	// 1. 큰 수를 작은 수로 나누는 MOD 연산을 수행합니다.

	// 2. 앞 단계에서의 작은 수와 MOD 연산의 결과값으로 MOD 연산을 수행합니다.

	// 3. 단계 2를 반복하다가 나머지가 0이 되는 순간의 작은 수가 최대 공약수입니다.

	cout << "최대공약수의 값 : " << Euclid(36, 18);

#pragma endregion


	return 0;
}