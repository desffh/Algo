#include <iostream>


using namespace std;

// 문자열 매칭
// 1. Naive방식
// 2. Rabin - Karp 알고리즘
// 3. 오토 마타
// 4. 보이어 무어
// 5. KMP

void Naive(const char * key, const char * other)
{
	// 시간 복잡도 n * m
	int n = strlen(key);
	int m = strlen(other);

	int j = 0;

	for (int i = 0; i < n - m; i++)
	{
		for (j = 0; j < m; j++)
		{
			if (key[i + j] != other[j])
			{
				break;
			}
		}

		if(j == m)
		{
			cout << "Pattern Found at Index" << i << endl;
		}
	}
}

// 65 66 67
// A  B  C

void RabinKarp(const char* pattern, const char* text)
{
	int patternHash = 0;
	int Hash = 0;
	int power = 1; // 곱하기 누적

	int patternSize = strlen(pattern);
	int textSize = strlen(text);

	for (int i = 0; i <= patternSize - textSize; i++)
	{
		if (i == 0)
		{
			for (int j = 0; j < textSize; j++)
			{
				patternHash = patternHash + pattern[textSize - 1 - j] * power;

				Hash = Hash + text[textSize - 1 - j] * power;

				if (j < textSize - 1)
				{
					power = power * 2;
				}
			}
		}
		else
		{
			patternHash = 2 * (patternHash - pattern[i - 1] * power) + pattern[textSize - 1 + i];
		}

		if (patternHash == Hash)
		{
			bool flag = true;

			for (int j = 0; j < textSize; j++)
			{
				if (pattern[i + j] != text[j])
				{
					flag = false;
					break;
				}
			}

			if (flag == true)
			{
				cout << i << "번째에서 발견하였습니다." << endl;
			}
		} 

	}

}


int main()
{
#pragma region 문자열 매칭

	// 문자열에 해싱 기법을 사용하여 해시 값으로
	// 비교하는 문자열 알고리즘입니다.


	//Naive("AABAAAB", "AA");
	// 0, 3, 4

	RabinKarp("BCABCD","ABC");

#pragma endregion




	return 0;
}