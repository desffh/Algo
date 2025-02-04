#include <iostream>
#define MAX 15
using namespace std;

int col[MAX];

// 퀸 갯수
int N = 0;

// 전체 경우의 수
int total = 0;

// 해당 위치 체크 (level = 행)
bool check(int level)
{
    for (int i = 0; i < level; i++)
    {
        // 서로 다른 행의 열이 같다면 && 열의 차 == 행의 차
        if (col[i] == col[level] || abs(col[level] - col[i]) == abs(level - i))
        {
            return false;
        }
    }
    
    return true;
}

// 행을 입력받고 가능할 열에 배치
void nqueen(int x)
{
    // 모든 행에 퀸이 배치되면 카운트++
    if (x == N)
    {
        total++;
    }
    else
    {
        for (int i = 0; i < N; i++)
        {
            col[x] = i; // 해당 위치에 퀸을 배치
            if (check(x)) // 유효한 위치라면, 다음 행을 판단 (나머지 열은 판단안하고 넘어감)
            {
                nqueen(x + 1);
            }
        }
    }
}
int main()
{
    cout << "배치할 퀸의 갯수 : ";
    cin >> N;
    nqueen(0);
    cout << "경우의 수 : " << total;
}