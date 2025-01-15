#include <iostream>
using namespace std;

// 입력한 n이 소수인지 판별
bool IsPrime(int n)
{
	if (n <= 1)
	{
		return false;
	}

	// n = 2일때 반복문 조건에 맞지 않아 실행x

	for (int i = 2; i < n; i++)
	{
		if (n % i == 0)
		{
			return false;// 0
		}
	}
	return true; // 1
}

// 에라토스테네스의 체
void Sieve(int n)
{
	int* array = new int[n + 1];

	// 값 초기화
	for (int i = 0; i <= n; i++)
	{
		array[i] = i;
	}

	// 소수 판별
	for (int i = 2; i < sqrt(n); i++)
	{

		if (array[i] == 0)
		{
			continue;
		}

		// j = i * i
		for (int j = i * 2; j <= n; j += i)
		{
			array[j] = 0;
		}
	}

	// 소수 출력
	for (int i = 2; i <= n; i++)
	{
		if (array[i] != 0)
		{
			cout << array[i] << " ";
		}
	}
	delete[] array;
}
int main()
{
	// cout << IsPrime(2);
	Sieve(16);
	return 0;
}