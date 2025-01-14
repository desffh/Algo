#include <iostream>
#define SIZE 5
using namespace std;



int main()
{
#pragma region 선택 정렬
	// 주어진 리스트 중에 최소값을 찾아서 맨 앞에 위치한
	// 결과를 교체하는 방식으로 정렬하는 알고리즘입니다.

	int min = 0;
	int minIndex = 0;

	int array[SIZE] = { 6, 2, 8, 1, 0 };

	// 마지막 값은 알아서 정렬되기 때문에 SIZE - 1
	// SIZE로 해도 무관하긴 함
	// 0 1 2 3 
	for (int i = 0; i < SIZE - 1; i++)
	{
		// 1. 최소값 찾기
		min = array[i];
		minIndex = i;

		for (int j = i + 1; j < SIZE; j++)
		{
			// 최소값 교체
			if (array[j] < min)
			{
				min = array[j];
				minIndex = j;
			}
		}
		// 실제 값 변경
		swap(array[i], array[minIndex]);
	}

	for (const int& element : array)
	{
		cout << element << " ";
	}

#pragma endregion


	return 0;
}
