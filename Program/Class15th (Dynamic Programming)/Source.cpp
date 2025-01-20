#include <iostream>
#define SIZE 100001
using namespace std;


int Fibonacchi(int n, int list[])
{

	if (n <= 0)
	{
		return 0;
	}
	else if (n <= 2)
	{
		return 1;
	}

	if (list[n] != 0)
	{
		return list[n];
	}

	return list[n] = Fibonacchi(n - 1, list) + Fibonacchi(n - 2, list);

}

int main()
{
#pragma region 동적 계획법
	// 특정 범위까지의 값을 구하기 위해서 그것과 
	// 다른 범위까지의 값을 이용하여 효율적으로 값을
	// 구하는 알고리즘입니다.


	// 메모이제이션
	// 프로그램이 동일한 계산을 반복해야 할 때, 이전에 
	// 계산한 값을 메모리에 저장함으로써 동일한 계산을
	// 반복 수행하는 작업을 제거하여 프로그램의 실행 속도를
	// 향상 시키는 방법입니다.

	int array[SIZE] = { 0, };
	cout << Fibonacchi(43, array) << endl;


	// Bottom Up -> 재귀를 사용하지 않고 for문 사용
	// list[i] = list[i- 1] + list[i - 2]
	// 큰 문제를 작은 문제로 나누어 해결해 나가는 방식으로, 이전에
	// 작은 문제의 결과를 재활용하여 큰 문제를 해결합니다.

	// 작은 문제의 결과를 저장하는 배열이 필요하므로, 배열의 크기는 
	// 입력 크기에 비례합니다.


	// Top Down
	// 메모이제이션을 사용하여 이전에 계산한 값을 저장해서 활용합니다.

	// 캐시에 사용되는 배열의 크기는 입력 크기와 같거나 작기 때문에 
	// 메모리 사용량이 상대적으로 작습니다.

#pragma endregion



	return 0;
}