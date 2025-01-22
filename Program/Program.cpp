#include <iostream>
#define SIZE 7
using namespace std;

class Graph
{
private:
	// 부모 배열
	int parent[SIZE];
	

public:
	Graph()
	{
		for (int i = 1; i < SIZE; i++)
		{
			parent[i] = i;
		}
	}

	int Find(int x)
	{
		if (parent[x] == x)
		{
			return x;
		}

		else
		{
			return parent[x] = Find(parent[x]);
		}
	}
};


int main()
{
#pragma region 유니온 파인드
	// 여러 노드가 존재할 때 어떤 노드가 다른 노드와 
	// 연결되어 있는 지 확인하는 알고리즘입니다.

	// Union 연산 : 특정한 두 개의 노드를 같은 집합으로 합치는 연산입니다.

	// Find 연산 : 특정한 노드가 어느 집합에 있는 지 확인하는 연산입니다.

	// 시간 복잡도
	// O(M log N) : M 연산의 개수, N은 노드의 개수
	// M이 N²에 가까울 때 O(N²logN)이 됩니다.
#pragma endregion

	return 0;
}