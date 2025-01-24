#include <iostream>
#define SIZE 6
#define INF 10000000
using namespace std;

// INF -> 무한대
// 1. 방문체크 배열 (T/F)
// 2. 가중치(거리) 배열 -> 1. 해당 정점과 연결된 거리 넣어주기(배열 크기만큼 다)
//						 2. 방문체크 해주기(해당 정점)
// 3. 인접행렬

class Graph
{
private:
	bool visited[SIZE];

	int distance[SIZE];

	int weight[SIZE][SIZE] =
	{
		{0,    2,   5,   1,   INF,  INF},
		{2,    0,   3,   2,   INF,  INF},
		{5,    3,   0,   3,     1,    5},
		{1,    2,   3,   0,     1,  INF},
		{INF,INF,   1,   1,     0,    2},
		{INF,INF,   5, INF,     2,    0}
	};


public:
	Graph()
	{
		for (int i = 0; i < SIZE; i++)
		{
			visited[i] = false;
			distance[i] = 0;
		}
	}

	void Dijkstra(int start)
	{
		for (int i = 0; i < SIZE; i++)
		{
			distance[i] = weight[start][i];
			//cout << distance[i] << " ";
		}
		visited[start] = true;

		for (int i = 0; i < SIZE - 1; i++)
		{
			int minNode = Find();

			visited[minNode] = true;

			for (int j = 0; j < SIZE; j++)
			{
				if (visited[j] == false)
				{
					if (distance[minNode] + weight[minNode][j] < distance[j])
					{
						distance[j] = distance[minNode] + weight[minNode][j];
					}
				}
			}
		}

		for (int i = 0; i < SIZE; i++)
		{
			cout << distance[i] << " ";
		}
	}

	// 배열의 최솟값의 인덱스를 찾는 함수
	const int& Find()
	{
		int position = 0;
		int min = INF;

		// 방문체크 되지않은 정점 탐색
		for (int i = 0; i < SIZE; i++)
		{
			if (distance[i] < min && visited[i] == false)
			{
				min = distance[i];
				position = i;
			}
		}
		return position;
	}
};


int main()
{
#pragma region 다익스트라 알고리즘
	// 시작점으로부터 모든 노드까지의 최소 거리를 구해주는
	// 알고리즘입니다.

	// 1. distance 배열에 weight[시작점 노드]의 값들로
	//	  초기화합니다.

	// 2. 시작점을 방문 처리합니다.

	// 3. distance 배열에서 최소 비용 노드를 찾고 방문 처리합니다.
	//    단, 이미 방문한 노드는 제외합니다.

	// 4. 최소 비용 노드를 거쳐갈 지 생각해서 distance 배열을 갱신합니다.
	//	  단, 이미 방문한 노드는 제외합니다.

	// 5. 모든 노드를 방문할 때까지 3번 ~ 4번을 반복합니다.

	// 방문하지 않은 노드 중에서 가장 적은 distance를 가진 노드를
	// 방문하고, 그 노드와 연결된 다른 노드까지의 거리를 계산합니다.

	Graph graph;

	graph.Dijkstra(0);

#pragma endregion




	return 0;
}