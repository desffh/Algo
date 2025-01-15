#include <iostream>
#define SIZE 5
using namespace std;

void TwoPointer(int m)
{
	int start = 0;
	int end = 0;

	int sum = 0;
	int count = 0;

	int array[SIZE] = { 1,2,3,2,5 };

	while (start <= end)
	{
		if (sum >= m)
		{
			sum -= array[start++];
		}
		else if (end >= SIZE)
		{
			break;
		}
		else if (sum < m)
		{
			sum += array[end++];
		}
		if (sum == m)
		{
			count++;
		}
	}

	cout << count;

}


int main()
{
#pragma region 투 포인터
	// 두 개의 포인터를 활용해서 배열의 요소를 효과적으로
	// 탐색하는 알고리즘입니다.

	// 1. 시작점과 끝나는 지점이 첫번째 원소를 가리키도록 합니다.

	// 2. 현재 부분합이 m보다 크거나 같다면 start를 1 증가시킵니다.

	// 3. 현재 부분합이 m보다 작다면 end를 1 증가시킵니다.

	// 4. 현재 부분합이 m과 같다면 count를 증가시킵니다.

	TwoPointer(5);

#pragma endregion


	return 0;
}
