#include <iostream>
#include <vector>
#include <queue>
#define SIZE 8
using namespace std;

class Graph
{
private:
	bool visited[SIZE];

	// 인접 리스트
	vector<int> graph[SIZE];

	queue<int> queue;

public:
	Graph()
	{
		for (int i = 0; i < SIZE; i++)
		{
			visited[i] = false;
		}
	}

	void Insert(int vertex, int edge)
	{
		graph[vertex].push_back(edge);
		graph[edge].push_back(vertex);
	}

	void Search(int start)
	{
		// 1. 큐에 넣고, 임시변수에 넣고 방문체크 하고,큐에서 빼고 출력

		// 큐에 값 넣기
		queue.push(start);

		visited[start] = true;

		while (!queue.empty())
		{
			// 큐 시작값 넣기
			int x = queue.front();

			queue.pop();

			cout << x << " "; // 저장된 x값 출력

			for (int i = 0; i < graph[x].size(); i++)
			{
				int next = graph[x][i];

				if (!visited[next])
				{
					// 큐에 인접노드 값 넣기
					queue.push(next);
					visited[next] = true;// 방문 체크
				}
			}
		}
	}
};

int main()
{
#pragma region 너비 우선 탐색 (Breadth First Search)
	// 시작 정점을 방문한 후 시작 정점에 인접한
	// 모든 정점들을 우선 방문하는 방법입니다.

	// 더 이상 방문하지 않은 정점이 없을 때까지
	// 방문하지 않은 모든 정점들에 대해서도 너비 우선 탐색을 적용합니다.

	Graph graph;

	graph.Insert(1, 2);
	graph.Insert(1, 3);

	graph.Insert(2, 4);
	graph.Insert(2, 5);

	graph.Insert(3, 6);
	graph.Insert(3, 7);


	graph.Search(1);
#pragma endregion





	return 0;
}