#include <iostream>
#define SIZE 4
using namespace std;

int Find(int list[], int left, int right)
{
	// 탈출할 수 있는 코드가 먼저 와야한다
	if (left == right)
	{
		return list[left];
	}

	else
	{
		int middle = (left + right) / 2;

		int maxLeft = Find(list, left, middle);
		int maxRight = Find(list, middle + 1, right);

		if (maxLeft < maxRight)
		{
			return maxRight;
		}
		else
		{
			return maxLeft;
		}
	}
}

// 분할 정복
int main()
{
#pragma region 분할 정복
	// 주어진 2개 이상의 부분으로 문제를 나눈 뒤 각 부분
	// 문제에 대한 답을 재귀적으로 호출하여 계산한 다음,
	// 답으로부터 전체 문제의 답을 계산해내는 알고리즘입니다.

	// 분할(Divide) :  주어진 문제를 두 개 혹은 그 이상의 형식으로 나눈다.

	// 정복(Conquer) : 나누어진 문제를 재귀적으로 해결해서 나누어진 문제를 
	//				   더 이상 나누어서 문제가 필요없을 때까지 계속 분할합니다.

	// 통합(Combine) : 나누어서 해결한 문제들을 통합해서 원래 문제의 해답을 생성합니다.

	int list[SIZE] = { 20, 15 , 99, 1 };

	cout << "list의 최대값 : " << Find(list, 0, SIZE - 1) << endl;

#pragma endregion


	return 0;
}
