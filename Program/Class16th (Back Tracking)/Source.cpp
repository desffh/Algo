#include <iostream>

using namespace std;


void Permutation(int n, int list[], int depth)
{
	// 1. depth가 0일 때, 첫 번째 인덱스의 값을 선택하고, 
	//    모든 인덱스를 돌면서 (1,1), (1,2), (1,3)을 Swap합니다.

	// 2. depth가 1일 때, 두 번째 인덱스의 값을 선택하고,
	//	  두 번째 인덱스와 마지막 인덱스의 값을 Swap합니다.

	// 3. depth가 2일 때 마지막 인덱스와 마지막 인덱스를 Swap합니다.

	// 4. depth가 3일 때 depth가 뽑으려는 수와 같으므로 값을 출력합니다.

	// n - 1이어도 같은 이유
	if (depth == n)
	{
		for (int i = 0; i < n; i++)
		{
			cout << list[i] << " ";
		}
		cout << endl;
		return;
	}

	for (int i = depth; i < n; i++)
	{
		swap(list[depth], list[i]);
		Permutation(n, list, depth + 1);
		swap(list[i], list[depth]);
	}
}

int main()
{
#pragma region 백트래킹
	// 해를 찾아가는 도중에 지금의 경로가 해가 될 것 같지 않으면,
	// 더 이상 깊이 들어가지 않고, 이전 단계로 다시 
	// 돌아가는 알고리즘입니다.

	// 백트래킹의 유망성 판단
	// 해가 될 만한지 판단한 후에 유망하지 않다고 결정되면,
	// 그 노드의 이전 노드로 돌아가, 다음 자식 노드로 이동합니다.

	// 해가 될 만한 가능이 있으면 유망하다 (Promising)
	// 유망하지 않은 노드에 가지 않는 것  (Pruning)

	int n = 3;
	int element[3] = { 1,2,3 };
	int depth = 0;

	Permutation(n, element, depth);


#pragma endregion



	return 0;
}