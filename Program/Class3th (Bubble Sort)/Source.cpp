#include <iostream>
#define SIZE 5
using namespace std;



int main()
{
#pragma region 거품 정렬
	// 서로 인접한 두 원소를 비교하여 정렬하는 알고리즘입니다.
	// 오름차순 정렬

	int array[SIZE] = { 5, 8, 2, 1, 4 };

	// 회차가 거듭할수록 맨 마지막 인덱스의 값이 점차 정렬된다
	// 정렬이 확정된 뒷부분을 제외한 부분만 정렬해야해서 (SIZE - i) - 1

	// 회차
	for (int i = 0; i < SIZE - 1; i++)
	{
		// 안쪽 정렬
		for (int j = 0; j < (SIZE - i) - 1; j++)
		{
			// 왼쪽이 더 크다면 swap
			if (array[j] > array[j + 1])
			{
				swap(array[j], array[j + 1]);
			}
		}
	}

	for (const int& element : array)
	{
		cout << element << " ";
	}

#pragma endregion

	return 0;
}
