
#include <iostream>
#include <vector>
#include <stack>
#define SIZE 12
using namespace std;

class Graph
{
private:
	int id;						// 방문 순서를 세기 위한 변수.
	int parent[SIZE];			// 방문 순서대로 번호를 붙인 후 재귀를 통해, 각 순회의 시작점으로 갱신된다. 
	// 처음에는 id 변수를 활용해서 방문한 순서대로 번호를 붙여준다.

	bool finished[SIZE];		// SCC에 포함되었는지 여부를 확인. true면 SCC에 포함되었다는 의미이다.

	stack<int> stack;			// 스택

	vector<int> graph[SIZE];	// 간선을 표현하기 위한 이차원 벡터
	vector<vector<int>> scc;	// SCC 묶음을 기록하기 위한 이차원 벡터

public:
	Graph()
	{
		id = 0;

		for (int i = 0; i < SIZE; i++)
		{
			parent[i] = 0;
			finished[i] = false;
		}
	}

	void Insert(int vertex, int edge)
	{
		graph[vertex].push_back(edge);
	}

	int Search(int start)
	{
		parent[start] = ++id;			// 각 노드마다 고유 번호를 붙여준다. 순회 과정에서 먼저 방문한 노드가 더 작은 번호를 가지도록 만들기 위해 id 변수를 활용한다.

		stack.push(start);				// Stack에 자기 자신을 삽입.

		int minNum = parent[start];		// 자신이 포함된 사이클에서 가장 작은 값을 기억하기 위한 변수. 사이클의 시작 번호를 알기 위한 변수

		for (int i = 0; i < graph[start].size(); i++)
		{
			int nextNode = graph[start][i];

			if (parent[nextNode] == 0)						// 해당 이웃 노드를 방문하지 않았다면
			{
				minNum = min(minNum, Search(nextNode));		// 방문해서 번호 비교.(재귀해서 타고 들어가야한다.)

			}
			else if (!finished[nextNode])					// 방문했지만 scc에 포함되지는 않았다면 (시작점이라면)
			{
				minNum = parent[nextNode];					// 최솟값에 자기 번호 대입. min()이 의미가 없다.
				// 시작점에 다시 도달했을 때는 재귀에 안들어가니까 한 단계씩 이전으로 돌아감.
			}
		}

		if (minNum == parent[start])		// 순회 내의 가장 작은 번호가 자신의 번호라면. 즉, 시작점에 다시 도달했다면
		{
			vector<int> clone;				// 복사하기 위한 벡터 배열

			while (1)
			{
				int top = stack.top();		// 스택에 있는 값을 가져와서
				clone.push_back(top);		// 벡터에 넣고
				finished[top] = true;		// 넣은 값은 방문 체크 finished 체크해주고

				stack.pop();				// 스택에서 값 제거

				if (top == start)			// 만약 top이 start(순회의 시작점)과 같다면 break
				{
					break;
				}
			}
			scc.push_back(clone);			// SCC(벡터 배열)에 이번 scc값 넣어주기
		}

		return minNum;						// minNum 반환. (시작점 이후 한 단계씩 돌아갈 때, 시작점의 값을 가지고 돌아간다.)
		// 맨 마지막 시작점으로 다시 돌아왔을 때, 마지막 return은 아무런 의미도 없다.
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

#pragma endregion

	return 0;
}