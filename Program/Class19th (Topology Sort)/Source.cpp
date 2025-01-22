#include <iostream>
#include <queue>
#include <vector>
#define SIZE 8
using namespace std;

class Graph
{
private:
	int degree[SIZE - 1]; // 진입차수 배열
	queue <int> queue; // 인접 리스트
	vector <int> graph[SIZE]; // 그래프 저장  

public:
	Graph()
	{
		for (int i = 0; i < SIZE; i++)
		{
			degree[i] = NULL;
		}
	}

	// 방향 그래프 (간선을 연결하고 집입을 당하는 노드(edge)의 진입차수 배열에 ++)
	void Insert(int vertex, int edge)
	{
		graph[vertex].push_back(edge);
		degree[edge]++;
	}

	void Sort()
	{
		for (int i = 1; i < SIZE; i++)
		{
			if (degree[i] == 0)
			{
				queue.push(i);
			}
		}

		while (!queue.empty())
		{
			int x = queue.front();

			queue.pop();

			cout << x << " ";

			for (int i = 0; i < graph[x].size(); i++)
			{
				int start = graph[x][i];

				// 간선을 먼저 제거한 뒤
				degree[start]--;

				// 큐에 넣어줘야 함
				if (degree[start] == 0)
				{
					queue.push(start);
				}
			}
		}
	}
};




int main()
{
#pragma region 위상 정렬
	// 방향 그래프에 존재하는 각 정점들의 선행 순서를 지키며,
	// 모든 정점을 차례대로 진행하는 알고리즘입니다.

	// 그래프에 사이클이 발생하는 경우, 위상 정렬을 수행할 수 없습니다.

	// DAG(Directed Acyclic Graph) : 사이클이 존재하지 않는 그래프

	// 시간 복잡도 : O(V + E)

	// 위상 정렬하는 방법

	// 진입차수 degree

	// 1. 진입 차수가 0인 정점을 Queue에 삽입합니다.

	// (큐가 비어있지 않으면 x에 큐 제일 앞에 값 넣기 & pop & 출력)
	// 연결되있는 노드들 큐에 넣어주기

	// 2. Queue에서 원소를 꺼내 연결된 모든 간선을 제거합니다.

	// 3. 간선 제거 이후에 진입 차수가 0이 된 정점을 Queue에 삽입합니다.

	// 4. Queue가 비어있을 때까지 2번 ~ 3번을 반복합니다.

	Graph graph;

	graph.Insert(1, 2);
	graph.Insert(1, 5);

	graph.Insert(2, 3);
	graph.Insert(3, 4);

	graph.Insert(4, 6);

	graph.Insert(5, 6);
	graph.Insert(6, 7);

	graph.Sort();




#pragma endregion



	return 0;
}