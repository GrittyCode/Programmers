#include<iostream>

using namespace std;

#define MAX 15

int col[MAX]; //이 안에 들어가는 것이 열의 크기이다.
int N;
int cnt = 0;

bool Check(int colmn) //행을 매개변수로 받아준다.
{
    int comp = abs(col[colmn] - colmn);
    for (int i = 0; i < colmn; ++i)
    {
        if (col[colmn] == col[i] || colmn - i == abs(col[colmn] - col[i]))
            return false;
    }

    return true;
}

void SolveQueen(int colmn)
{
    if (colmn >= N)
    {
        ++cnt;
        return;
    }

    for (int i = 0; i < N; ++i)
    {
        col[colmn] = i;
        if (Check(colmn))
        {
            SolveQueen(colmn + 1);
        }
    }

    //Queen을 놓을 곳을 찾는다.

}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    SolveQueen(0);
    cout << cnt;
    return 0;
}