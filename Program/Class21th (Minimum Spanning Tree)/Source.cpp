#include <iostream>
#include <algorithm>
#include <vector>
#define SIZE 8
using namespace std;

// 유니온 파인드를 사용해서 사이클이 발생하는지 확인

class Graph
{
private:

	class Edge
	{
	private:
		int x;
		int y;
		int distance;

	public:
		Edge(int x, int y, int distance)
		{
			this->x = x;
			this->y = y;
			this->distance = distance;
		}

		const int& X()
		{
			return x;
		}
		const int& Y()
		{
			return y;
		}
		const int& Distance()
		{
			return distance;
		}

		// sort를 사용하기 위해 사용자 정의 연산자 오버로딩
		const bool& operator < (const Edge& edge)
		{
			return distance < edge.distance;
		}

	};



	int parent[SIZE]; // 부모배열

	int cost; // 최소비용 = 가중치의 합이 최소

	vector <Edge> graph; // 간선 정보를 저장할 벡터배열

public:
	Graph()
	{
		cost = 0;

		// 부모배열 초기화
		for (int i = 0; i < SIZE; i++)
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

	void Union(int x, int y)
	{
		x = Find(x);
		y = Find(y);

		if (x < y)
		{
			parent[y] = x;
		}
		else
		{
			parent[x] = y;
		}
	}

	bool Same(int x, int y)
	{
		return Find(x) == Find(y);
	}

	// 벡터에 간선 정보 삽입
	void Insert(int x, int y, int distance)
	{
		graph.push_back(Edge(x, y, distance));
	}

	void Kruskal()
	{
		// 오름차순 정렬
		sort(graph.begin(), graph.end());

		for (int i = 0; i < graph.size(); i++)
		{
			cout << graph[i].X() << " " << graph[i].Y()
				<< " " << graph[i].Distance() << endl;
		}

		for (int i = 0; i < graph.size(); i++)
		{
			// 정점x와 정점y의 root노드가 같다면 같은 집합이기 때문에 건너뛰기
			if (Same(graph[i].X(), graph[i].Y()))
			{
				continue;
			}

			// 다르다면 가중치를 누적하고 간선 연결(부모노드 갱신)
			else
			{
				cost += graph[i].Distance();

				Union(graph[i].X(), graph[i].Y());
			}
		}
		cout << "Graph 최소 비용 : " << cost << endl;
	}
};


int main()
{
#pragma region 신장 트리
	// 그래프의 모든 정점을 포함하면서 사이클이 존재하지 않는
	// 부분 그래프로, 그래프의 모든 정점을 최소 비용으로
	// 연결하는 트리입니다.

	// 그래프의 정점의 수가 n개일 때, 간선의 수는 n - 1개 입니다.

	// 최소 비용 신장 트리
	// 그래프의 간선들의 가중치 합이 최소인 신장 트리

	Graph graph;

	graph.Insert(1, 7, 10);
	graph.Insert(4, 7, 14);

	graph.Insert(1, 4, 25);
	graph.Insert(2, 4, 22);

	graph.Insert(1, 2, 63);
	graph.Insert(1, 5, 16);

	graph.Insert(2, 5, 60);
	graph.Insert(3, 5, 20);

	graph.Insert(3, 6, 31);
	graph.Insert(5, 6, 49);

	graph.Kruskal();




#pragma endregion





	return 0;
}