#include <iostream>
#define SIZE 8
using namespace std;

void BinarySearch(int list[], int key)
{
	int left = 0;
	int right = SIZE - 1;

	while (left <= right)
	{
		int pivot = (left + right) / 2;

		if (key == list[pivot])
		{
			cout << "Key Found : " << list[pivot];
			return;
		}
		else if (key > list[pivot])
		{
			left = pivot + 1;
		}
		else if (key < list[pivot])
		{
			right = pivot - 1;
		}
	}
	cout << "Not Key Found" << endl;
}

// 재귀사용방식

int main()
{
#pragma region 이진 탐색
	// 탐색 범위를 반으로 나누어 찾는 값을 포함하는 범위를
	// 좁혀나가는 방식으로 동작하는 알고리즘입니다.

	// 오름차순 정렬이 되어있는 상태에서 사용

	// right < left면 값을 못찾은 상태 (엇갈림)

	int list[SIZE] = { 1,2,30, 42,50, 55, 60,70 };

	BinarySearch(list, 30);

#pragma endregion



	return 0;
}
