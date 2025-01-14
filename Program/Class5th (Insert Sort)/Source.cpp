#include <iostream>
#define SIZE 5
using namespace std;



int main()
{
#pragma region 삽입 정렬
	// 데이터를 하나씩 확인하면서 이미 정렬된 부분과 비교하여
	// 자신의 위치를 찾아 삽입하는 방식으로 정렬하는 알고리즘입니다.

	// 키값과 왼쪽에 값들을 비교한 뒤 그 자리에 키값을 대입

	// 0번째 인덱스의 수는 그 자체로 정렬이 되어있으므로 [1]부터 시작
	int array[SIZE] = { 6,12,4,1,7 };

	int key = 0;

	int j = 0;

	// 1 2 3 4 
	for (int i = 1; i < SIZE; i++)
	{
		// 키값 저장
		key = array[i];

		for (j = i - 1; j >= 0 && array[j] > key; j--)
		{
			// key위치의 인덱스의 값을 j값으로 대입
			array[j + 1] = array[j];
		}
		

		// 비교 위치에 key값 삽입 (j가 -가 되는걸 방지)
		array[j + 1] = key;
	}
	
	for (const int& element : array)
	{
		cout << element << " ";
	}
#pragma endregion

	return 0;
}
