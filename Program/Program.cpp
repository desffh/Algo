#include <iostream>
#include <vector>
#include <stack>
#define SIZE 12

using namespace std;

class Graph
{
private:

	bool finished[SIZE]; // 방문 배열
	
	vector<vector<int>> scc; // scc저장벡터

	vector<int> graph[SIZE]; // 그래프

	int parent[SIZE]; // 부모 배열
	
	stack<int> stack;
	
	int id; 
public:
	Graph()
	{
		id = 0;

		for (int i = 0; i < SIZE; i++)
		{
			finished[i] = false;
			parent[i] = 0;
		}
	}

	void Insert(int vertex, int edge)
	{
		graph[vertex].push_back(edge);
	}

	int Search(int start)
	{
		parent[start] = ++id; // 노드마다 고유한 번호

		stack.push(start); // stack에 자기 자신을 삽입합니다.

		int x = parent[start];


		for (int i = 0; i < graph[start].size(); i++)
		{
			int next = graph[start][i];
			
			if (parent[next] == 0) // 방문하지 않은 이웃 노드
			{ 
				x = min(x, Search(next));
			}

			else if (!finished[next]) // 처리중인 이웃 노드
			{
				x = min(x, parent[next]);
			}
		}

		if (x == parent[start]) // 부모 노드가 자기 자신인 경우
		{
			vector <int> clone;

			while (1)
			{
				int top = stack.top();

				stack.pop();

				clone.push_back(top);

				finished[top] = true;

				if (top == start)
				{
					break;
				}
			}

			scc.push_back(clone);
		}

		return x;
	}

	const int & operator [] (int index)
	{
		return parent[index];
	}

	const int & Count()
	{
		return scc.size();
	}

	void Show()
	{
		for (int i = 0; i < scc.size(); i++)
		{
			for (int j = 0; j < scc[i].size(); j++)
			{
				cout << scc[i][j] << " ";
			}
			cout << endl;
		}
	}
};


int main()
{
#pragma region 강한 결합 요소
	// 유향 그래프에서 모든 정점이 모든 다른 정점에 대해
	// 도달 가능한 경우, 그래프는 강하게 연결되었다는 그래프입니다.

	Graph graph;

	graph.Insert(1, 2);
	graph.Insert(2, 3);
	graph.Insert(3, 1);

	graph.Insert(4, 2);
	graph.Insert(4, 5);

	graph.Insert(5, 7);
	graph.Insert(6, 5);
	graph.Insert(7, 6);

	graph.Insert(8, 5);
	graph.Insert(8, 9);

	graph.Insert(9, 10);
	graph.Insert(10, 11);

	graph.Insert(11, 3);
	graph.Insert(11, 8);
	
	for (int i = 1; i < SIZE; i++)
	{
		if (graph[i] == 0)
		{
			graph.Search(i);
		}
	}

	cout << graph.Count() << endl; 
	graph.Show();

#pragma endregion




	return 0;
}